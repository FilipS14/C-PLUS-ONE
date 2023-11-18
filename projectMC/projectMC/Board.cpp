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
	return 0;
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

void Board::drawMatrix(std::vector<std::vector< uint8_t>>& matrix) {

}

bool Board::isOccupied(uint8_t line, uint8_t column)
{
	if (m_matrix[line][column] == 1)
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
