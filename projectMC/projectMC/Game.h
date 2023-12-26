#pragma once
#include "Player.h"
#include "Board.h"
#include <memory>
#include <stack>

class Game
{
public:
	Game() :
		m_board(std::make_unique<Board>()),
		m_redPlayer(std::make_unique<Player>("default", Team::red)),
		m_blackPlayer(std::make_unique<Player>("deafult", Team::black)),
		m_currentPlayer(m_redPlayer.get())
	{}
	~Game() = default;

private:
	std::unique_ptr<Board> m_board;
	std::unique_ptr<Player> m_redPlayer;
	std::unique_ptr<Player> m_blackPlayer;
	Player* m_currentPlayer;
};
