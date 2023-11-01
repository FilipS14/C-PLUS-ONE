#pragma once
#include<iostream>
#include<cstdint>

class Board
{
public:
	Board();
	~Board();
	uint8_t  getLine();
	uint8_t getColumn();
	void setColumn(uint8_t line);
	void setLine(uint8_t column);
private:
	uint8_t** matrix;
	uint8_t line, column;
};

