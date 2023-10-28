#include"Board.h"

uint8_t Board::getLine() {
	return this->line;
}

uint8_t Board::getColumn() {
	return this->column;
}

void Board::setLine(uint8_t line) {
	this->line = line;
}

void Board::setColumn(uint8_t column) {
	this->column = column;
}


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

Board::Board(const Board& other) {
	this->line = other.line;
	this->column = other.column;
	if (other.matrix != nullptr)
	{
		this->matrix = new uint8_t *[this->line];
		for (uint8_t i = 0; i < this->line; ++i)
		{
			this->matrix[i] = new uint8_t[this->column];
			for (uint8_t j = 0; j < this->column; ++j)
			{
				this->matrix[i][j] = other.matrix[i][j];
			}
		}
	}
	else {
		this->matrix = nullptr;
	}
}
