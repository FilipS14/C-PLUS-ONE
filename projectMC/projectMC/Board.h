#pragma once
#include<iostream>
#include<cstdint>
#include<vector>
#include "Cell.h"
#include "Pillar.h"
#include "Bridge.h"

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

	//Getteri
	uint8_t getLine() const;
	uint8_t getColumn() const;
	std::vector<std::vector<Cell>>& getMatrix();

	//Setteri
	void setLine(uint8_t line);
	void setColumn(uint8_t column);
	
	//Matrix manipulation
	void addCell(size_t line, size_t column, QPoint coordinates);
	Cell getCell(uint32_t x, uint32_t y) const;
	void resizeBoard(size_t line, size_t column);
	void addPillar(const Pillar& pillar);
	void addBridge(const Bridge& bridge);

private:
	uint8_t m_line, m_column;
	std::vector<std::vector<Cell>>m_board;
};

