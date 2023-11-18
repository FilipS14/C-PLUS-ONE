#pragma once
#include<iostream>
#include<cstdint>
#include<vector>

class Board
{
public:
	Board(uint8_t line, uint8_t column);
	Board() = default;
	~Board() = default;
	uint8_t getLine() const;
	uint8_t getColumn() const;
	void setLine(uint8_t line);
	void setColumn(uint8_t column);
	void drawMatrix(std::vector<std::vector< uint8_t>>& matrix);
	bool isOccupied(uint8_t line, uint8_t column);

private:
	uint8_t m_line, m_column;
	std::vector<std::vector<uint8_t>>m_matrix;
};

