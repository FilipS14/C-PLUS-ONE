#pragma once
#include "Cell.h"
#include "Pillar.h"
#include "Bridge.h"
#include "Player.h"
#include <QPoint>
#include <QColor>
#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <array>

struct TwoPoint {
	QPoint point1;
	QPoint point2;

	bool operator==(const TwoPoint& other) const {
		return point1 == other.point1 && point2 == other.point2;
	}
};

struct TwoPointHash {
	std::size_t operator()(const TwoPoint& tp) const {
		std::size_t h1 = std::hash<int>()(tp.point1.x()) ^ std::hash<int>()(tp.point1.y());
		std::size_t h2 = std::hash<int>()(tp.point2.x()) ^ std::hash<int>()(tp.point2.y());
		return h1 ^ (h2 << 1);
	}
};

struct PillarHash {
	std::size_t operator()(const QPoint& point) const {
		std::size_t h1 = std::hash<int>()(point.x());
		std::size_t h2 = std::hash<int>()(point.y());
		return h1 ^ (h2 << 1);
	}
};

class Board
{
public:
	//rule of 5
	Board(uint8_t line, uint8_t column); //Constructor
	Board() = default; //Constructor
	Board(Board&& other) noexcept; //Move Constructor
	Board& operator=(Board&& other)noexcept; // Move Assignament Constructor
	Board(const Board& other); //Copy Constructor
	Board& operator=(const Board& other); //Copy Assignament Operator
	~Board() = default; //Destructor

	//GETTERS
	uint8_t getLine() const;
	uint8_t getColumn() const;
	std::vector<std::vector<Cell>>& getMatrix();
	std::unordered_map<QPoint, Pillar, PillarHash>& getPillars();
	std::unordered_map<TwoPoint, Bridge, TwoPointHash>& getBridges();
	std::vector<Cell> getRedBase() const;
	std::vector<Cell> getBlackBase() const;

	//SETTERS
	void setLine(uint8_t line);
	void setColumn(uint8_t column);
	
	//MATRIX HANDLING
	void addCell(size_t line, size_t column, QPoint coordinates);
	Cell getCell(uint32_t x, uint32_t y) const;
	void resizeBoard(size_t line, size_t column);

	//PILLAR AND BRIDGES HANDLING
	void addPillar(const Pillar& pillar);
	void addBridge(const Bridge& bridge);
	void removeBridge(const Cell& startCell, const Cell& endCell);

	//CHECKS CALLED
	bool isValidPillarMove(const Cell& cell, const Player& player);
	bool isValidBridgeMove(const Cell& startCell, const Cell& endCell, const Player& player);

	//CHECKS BRIDGES
	bool areCellsOccupied(const Cell& startCell, const Cell& endCell);
	bool areCellsPillars(const Cell& startCell, const Cell& endCell);
	bool arePillarsSameColor(const Cell& startCell, const Cell& endCell);
	bool arePillarsPlayerColor(const Cell& startCell, const Cell& endCell, const Player& player);
	bool checkDistaceToBridge(const Cell& startCell, const Cell& endCell);
	bool checkBridgesIntersection(const Cell& startCell, const Cell& endCell);
	bool doSegmentsIntersect(const QPoint& start1, const QPoint& end1, const QPoint& start2, const QPoint& end2);
	int orientation(const QPoint& p, const QPoint& q, const QPoint& r);


	//CHECKS PILLARS
	bool checkPillarsOverlap(const Cell& Cell);
	bool checkOpponentBase(const Cell& Cell, const Player& Player);

private:
	uint8_t m_line, m_column;
	std::vector<std::vector<Cell>>m_board;
	std::unordered_map<QPoint, Pillar, PillarHash> m_pillars;
	std::unordered_map<TwoPoint, Bridge, TwoPointHash> m_bridges;
};

