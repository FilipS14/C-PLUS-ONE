#include"Board.h"

Board::Board(uint8_t line ,uint8_t column)
{
	this->line = line;
	this->column = column;
	matrix = new uint8_t* [line];
	for (int i = 0; i < line; i++){
		matrix = new uint8_t[column];
	}
}

Board::~Board()
{
	for (int i = 0; i < line; i++)
	{
		delete[]matrix[i];
	}
	delete[] matrix;
}
