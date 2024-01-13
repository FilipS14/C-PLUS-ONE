#pragma once
#include "../backend/Player.h"
#include "../backend/Board.h"
#include <QMessageBox>
#include <functional>
#include <memory>
#include <stack>

namespace std {
	template <>
	struct hash<QPoint> {
		std::size_t operator()(const QPoint& point) const {
			return std::hash<int>()(point.x()) ^ (std::hash<int>()(point.y()) << 1);
		}
	};
}

struct CellHash {
	std::size_t operator()(const Cell& c) const {
		return std::hash<QPoint>()(c.getCoordinates());
	}
};

struct CellEqual {
	bool operator()(const Cell& c1, const Cell& c2) const {
		return c1.getCoordinates() == c2.getCoordinates();
	}
};


class Game
{
public:
	Game();
	~Game() = default;
	//GETTERS
	Board& getBoard() const;
	Player& getRedPlayer() const;
	Player& getBlackPlayer() const;
	Player& getCurrentPlayer() const;

	//PLACEMENT OF PILLARS AND BRIDGES
	void placePillar(Cell& cell, Player& player);
	void placeBridge(const Cell& cellStart, const Cell& cellEnd, Player& player);

	//GAME HANDLER
	bool checkDrawCondition();
	bool switchToRedPlayer();
	bool switchToBlackPlayer();
	void initializationGame(uint8_t line, uint8_t column);
	bool checkWinCondition(Player& player);
	bool dfsTraversal(Player& player, const Cell& startCell, std::unordered_set<Cell, CellHash, CellEqual>& visitedCells, const int dX[], const int dY[]);
	bool reachedEnd(const Cell& cell) const;
	void processNeighborCell(Player& player, const Cell& currentCell, std::unordered_set<Cell, CellHash, CellEqual>& visitedCells, int dX, int dY, std::stack<Cell>& stackDfs) const;
	void handleBridge(Player& player, const Cell& currentCell, const Cell& neighborCell, std::unordered_set<Cell, CellHash, CellEqual>& visitedCells, std::stack<Cell>& stackDfs) const;

	//MINE
	bool redTurn();
	void mineSwitchTurn(Cell& cell, Player& player);


private:
	std::unique_ptr<Board> m_board;
	std::unique_ptr<Player> m_redPlayer;
	std::unique_ptr<Player> m_blackPlayer;
	Player* m_currentPlayer;
};
