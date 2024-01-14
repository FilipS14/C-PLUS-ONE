#include "Game.h"

Game::Game() :
    m_board(std::make_unique<Board>()),
    m_redPlayer(std::make_unique<Player>("default", Team::red)),
    m_blackPlayer(std::make_unique<Player>("deafult", Team::black)),
    m_currentPlayer(m_redPlayer.get())
{}

//GETTERS
Board& Game::getBoard() const
{
    return *m_board;
}

Player& Game::getRedPlayer() const
{
    return *m_redPlayer;
}

Player& Game::getBlackPlayer() const
{
    return *m_blackPlayer;
}

Player& Game::getCurrentPlayer() const {
    return *m_currentPlayer;
}

DataBaseManager Game::getDataBase() const
{
    return m_dataBase;
}

bool Game::redTurn() {
    if (m_currentPlayer == m_redPlayer.get()) {
        return true;
    }
    return false;
}

//GAME HANDLER
void Game::initializationGame(uint8_t line, uint8_t column) {
    //trbuie sa ma uit aici
    m_currentPlayer = m_redPlayer.get();
    m_board.get()->resizeBoard(line, column);
}

bool Game::checkWinCondition(Player& player) {
    const int dX[8]{ -2, -2, -1, -1, 1, 1, 2, 2 }, dY[8]{ -1, +1, -2, +2, -2, +2, -1, +1 };
    std::unordered_set<Cell, CellHash, CellEqual> visitedCells;
    std::vector<Cell> vectorBase;

    vectorBase = (player.getTeam() == Team::red) ? m_board->getRedBase() : m_board->getBlackBase();

    for (const auto& baseCell : vectorBase) {
        if (baseCell.getOcupier()) {
            visitedCells.emplace(baseCell);
            if (dfsTraversal(player, baseCell, visitedCells, dX, dY)) {
                return true;
            }
        }
    }
    return false;
}

bool Game::reachedEnd(const Cell& cell) const {
    return cell.getLine() == m_board.get()->getLine() - 1 ||
        cell.getColumn() == m_board.get()->getColumn() - 1;
}

bool Game::checkDrawCondition() {
    return m_redPlayer.get()->getNumberOfPillars() <= 0 &&
        m_redPlayer.get()->getNumberOfBridges() <= 0 &&
        m_blackPlayer.get()->getNumberOfPillars() <= 0 &&
        m_blackPlayer.get()->getNumberOfBridges() <= 0;
}

bool Game::dfsTraversal(Player& player, const Cell& startCell, std::unordered_set<Cell, CellHash, CellEqual>& visitedCells, const int dX[], const int dY[]) {
    std::stack<Cell> stackDfs;
    stackDfs.push(startCell);

    while (!stackDfs.empty()) {
        Cell currentCell = stackDfs.top();
        stackDfs.pop();

        if (reachedEnd(currentCell)) {
            return true;
        }

        for (size_t i = 0; i < 8; i++) {
            processNeighborCell(player, currentCell, visitedCells, dX[i], dY[i], stackDfs);
        }
    }
    return false;
}

void Game::processNeighborCell(Player& player, const Cell& currentCell, std::unordered_set<Cell, CellHash, CellEqual>& visitedCells, int dX, int dY, std::stack<Cell>& stackDfs) const {
    auto newX = currentCell.getLine() + dX;
    auto newY = currentCell.getColumn() + dY;

    auto isValidCell = [this](const int& x, const int& y) {
        return x >= 0 && x < m_board->getLine() && y >= 0 && y < m_board->getColumn();
    };

    if (isValidCell(newX, newY)) {
        const Cell& neighborCell = m_board.get()->getMatrix().at(newX).at(newY);

        if (visitedCells.find(neighborCell) == visitedCells.end()) {
            handleBridge(player, currentCell, neighborCell, visitedCells, stackDfs);
        }
    }
}

void Game::handleBridge(Player& player, const Cell& currentCell, const Cell& neighborCell, std::unordered_set<Cell, CellHash, CellEqual>& visitedCells, std::stack<Cell>& stackDfs) const {
    auto bridgeIt1 = m_board.get()->getBridges().find({ currentCell.getCoordinates(), neighborCell.getCoordinates() });
    auto bridgeIt2 = m_board.get()->getBridges().find({ neighborCell.getCoordinates(), currentCell.getCoordinates() });
    if (bridgeIt1 != m_board.get()->getBridges().end() || bridgeIt2 != m_board.get()->getBridges().end()) {
        stackDfs.push(neighborCell);
        visitedCells.insert(neighborCell);
    }
}

void Game::gameReset()
{
    m_board->resetBridge();
    m_board->resetPillar();
    for (size_t line = 0; line < m_board->getLine(); ++line) {
        for (size_t column = 0; column < m_board->getColumn(); ++column) {
            m_board->getMatrix()[line][column].clearCell();
        }
    }
    const uint8_t pieces { 50 };
    m_redPlayer.get()->setNumberOfPillars(pieces);
    m_redPlayer.get()->setNumberOfBridges(pieces);
    m_blackPlayer.get()->setNumberOfPillars(pieces);
    m_blackPlayer.get()->setNumberOfBridges(pieces);
    m_board->generateMines();
}

bool Game::switchToRedPlayer() {
    if (!m_currentPlayer->getMovePillar()) {
        return false;
    }
    m_currentPlayer->setMovePillar(false);
    m_currentPlayer = m_redPlayer.get();
    return true;
}

bool Game::switchToBlackPlayer() {
    if (!m_currentPlayer->getMovePillar()) {
        return false;
    }
    m_currentPlayer->setMovePillar(false);
    m_currentPlayer = m_blackPlayer.get();
    return true;
}

void Game::placePillar(Cell& cell, Player& player) {
    if (!m_board->isValidPillarMove(cell, player)) {
        return;
    }

    cell.setOcupied(true);

    QColor color = (player.getTeam() == Team::red) ? Qt::red : Qt::black;

    Pillar newPillar{ cell.getCoordinates(), color };
    m_board.get()->addPillar(newPillar);

    player.updateNumberOfPillars(1);
    player.setMovePillar(true);
}

void Game::placeBridge(const Cell& cellStart, const Cell& cellEnd, Player& player) {
    if (!m_board->isValidBridgeMove(cellStart, cellEnd, player)) {
        return;
    }

    QColor color = (player.getTeam() == Team::red) ? Qt::red : Qt::black;

    Bridge newBridge{ cellStart.getCoordinates(), cellEnd.getCoordinates(), color };
    m_board->addBridge(newBridge);
    player.updateNumberOfBridges(1);

}

void Game::mineSwitchTurn(Cell& cell, Player& player) {
    cell.setOcupied(true);
    player.updateNumberOfPillars(1);
    player.setMovePillar(true);
}

void Game::loadPillars(std::ifstream& inFile) {
    int pillarCount;
    inFile >> pillarCount;
    Player* pillar_m_currentPlayer;
    for (int i = 0; i < pillarCount; ++i) {
        int line, column, color;
        inFile >> line >> column >> color;
        if (color == 1) {
            pillar_m_currentPlayer = m_redPlayer.get();
        }
        else {
            pillar_m_currentPlayer = m_blackPlayer.get();
        }
        placePillar(m_board->getMatrix()[line][column], *pillar_m_currentPlayer);
    }
}

void Game::loadBridges(std::ifstream& inFile) {
    int bridgeCount;
    inFile >> bridgeCount;
    Player* bride_m_currentPlayer;
    for (int i = 0; i < bridgeCount; ++i) {
        int line1, column1, line2, column2, color;
        inFile >> line1 >> column1 >> line2 >> column2 >> color;
        if (color == 1) {
            bride_m_currentPlayer = m_redPlayer.get();
        }
        else {
            bride_m_currentPlayer = m_blackPlayer.get();
        }
        placeBridge(m_board->getMatrix()[line1][column1], m_board->getMatrix()[line2][column2], *bride_m_currentPlayer);
    }
}

void Game::loadData(const std::string& filename) {
    std::ifstream inFile(filename);

    if (inFile.is_open()) {
        loadPillars(inFile);
        loadBridges(inFile);

        inFile.close();
        std::cout << "Data loaded from " << filename << std::endl;
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
