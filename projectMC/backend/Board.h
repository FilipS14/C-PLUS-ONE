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
#include <random>

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
	__declspec(dllexport) Board(uint8_t line, uint8_t column); //Constructor
	__declspec(dllexport) Board() = default; //Constructor
	__declspec(dllexport) Board(Board&& other) noexcept; //Move Constructor
	__declspec(dllexport) Board& operator=(Board&& other)noexcept; // Move Assignament Constructor
	__declspec(dllexport) Board(const Board& other); //Copy Constructor
	__declspec(dllexport) Board& operator=(const Board& other); //Copy Assignament Operator
	__declspec(dllexport) ~Board() = default; //Destructor

	//GETTERS
	__declspec(dllexport) uint8_t getLine() const;
	__declspec(dllexport) uint8_t getColumn() const;
	__declspec(dllexport) std::vector<std::vector<Cell>>& getMatrix();
	__declspec(dllexport) std::unordered_map<QPoint, Pillar, PillarHash>& getPillars();
	__declspec(dllexport) std::unordered_map<TwoPoint, Bridge, TwoPointHash>& getBridges();
	__declspec(dllexport) std::vector<Cell> getRedBase() const;
	__declspec(dllexport) std::vector<Cell> getBlackBase() const;

	//SETTERS
	__declspec(dllexport) void setLine(uint8_t line);
	__declspec(dllexport) void setColumn(uint8_t column);

	//MATRIX HANDLING
	__declspec(dllexport) void addCell(size_t line, size_t column, QPoint coordinates);
	__declspec(dllexport) Cell getCell(uint32_t x, uint32_t y) const;
	__declspec(dllexport) void resizeBoard(size_t line, size_t column);

	//PILLAR AND BRIDGES HANDLING
	__declspec(dllexport) void addPillar(const Pillar& pillar);
	__declspec(dllexport) void addBridge(const Bridge& bridge);
	__declspec(dllexport) void removeBridge(const Cell& startCell, const Cell& endCell);

	//CHECKS CALLED
	__declspec(dllexport) bool isValidPillarMove(const Cell& cell, const Player& player);
	__declspec(dllexport) bool isValidBridgeMove(const Cell& startCell, const Cell& endCell, const Player& player);

	//CHECKS BRIDGES
	__declspec(dllexport) bool areCellsOccupied(const Cell& startCell, const Cell& endCell);
	__declspec(dllexport) bool areCellsPillars(const Cell& startCell, const Cell& endCell);
	__declspec(dllexport) bool arePillarsSameColor(const Cell& startCell, const Cell& endCell);
	__declspec(dllexport) bool arePillarsPlayerColor(const Cell& startCell, const Cell& endCell, const Player& player);
	__declspec(dllexport) bool checkDistaceToBridge(const Cell& startCell, const Cell& endCell);
	__declspec(dllexport) bool checkBridgesIntersection(const Cell& startCell, const Cell& endCell);
	__declspec(dllexport) bool doSegmentsIntersect(const QPoint& start1, const QPoint& end1, const QPoint& start2, const QPoint& end2);
	__declspec(dllexport) int orientation(const QPoint& p, const QPoint& q, const QPoint& r);


	//CHECKS PILLARS
	__declspec(dllexport) bool checkPillarsOverlap(const Cell& Cell);
	__declspec(dllexport) bool checkOpponentBase(const Cell& Cell, const Player& Player);

	//MINES
	__declspec(dllexport) int generateRandomNumber(uint8_t minValue, uint8_t maxValue) const;
	__declspec(dllexport) void generateMines();

private:
	uint8_t m_line, m_column;
	std::vector<std::vector<Cell>>m_board;
	std::unordered_map<QPoint, Pillar, PillarHash> m_pillars;
	std::unordered_map<TwoPoint, Bridge, TwoPointHash> m_bridges;
};

