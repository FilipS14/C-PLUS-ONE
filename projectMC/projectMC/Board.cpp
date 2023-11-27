#include"Board.h"

Board::Board(uint8_t line, uint8_t column) :
	m_line{ line },
	m_column{ column },
	m_matrix(line, std::vector<uint8_t>(column, 0)) {
}

uint8_t Board::getLine() const {
	return m_line;
}

uint8_t Board::getColumn() const {
	return m_column;
}

uint8_t Board::getValue(uint8_t line, uint8_t column) const
{
	return m_matrix[line][column];
}

void Board::setLine(uint8_t line) {
	m_line = line;
}

void Board::setColumn(uint8_t column) {
	m_column = column;
}

void Board::setValue(uint8_t line, uint8_t column, uint8_t value)
{
	m_matrix[line][column] = value;
}

bool Board::isOccupied(uint8_t line, uint8_t column)
{
	if (m_matrix[line][column] == 1)
	{
		return false;
	}
	return true;
}

bool Board::isValidMove(uint8_t line, uint8_t column, bool isBlack)
{
	if (m_matrix[line][column] == 1)
	{
		return false;
	}
	else if(isBlack == true && (line < 1 || line > m_matrix.size() - 2))
	{
		return false;
	}
	else if (isBlack == false && (column < 1 || column  > m_matrix[line].size() - 2))
	{
		return false;
	}
	return true;
}

void Board::reset()
{
	for (uint8_t i = 0; i < m_line; ++i)
	{
		for (uint8_t j = 0; j < m_column; ++j)
		{
			m_matrix[i][j] = 0;
		}
	}
}
