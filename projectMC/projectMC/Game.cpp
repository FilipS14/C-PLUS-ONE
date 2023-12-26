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
