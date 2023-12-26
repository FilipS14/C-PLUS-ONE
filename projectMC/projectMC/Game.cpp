#include "Game.h"

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

//GAME HANDLER
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

