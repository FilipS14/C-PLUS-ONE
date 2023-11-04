#include"Board.h"

Board::Board(uint8_t line, uint8_t column) :
	m_line{ line },
	m_column{ column } {
}

uint8_t Board::getLine() const {
	return m_line;
}

uint8_t Board::getColumn() const {
	return m_column;
}

void Board::setLine(uint8_t line) {
	m_line = line;
}

void Board::setColumn(uint8_t column) {
	m_column = column;
}

void Board::drawMatrix(std::vector<std::vector< uint8_t>>& matrix) {

}