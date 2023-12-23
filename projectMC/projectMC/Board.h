#pragma once
#include "Cell.h"
#include "Pillar.h"
#include "Bridge.h"
#include "Player.h"
#include <QPoint>
#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>

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

private:
	uint8_t m_line, m_column;
	std::vector<std::vector<Cell>>m_board;
	std::unordered_map<QPoint, Pillar, PillarHash> m_pillars;
};

