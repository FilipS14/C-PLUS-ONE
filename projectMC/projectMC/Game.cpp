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