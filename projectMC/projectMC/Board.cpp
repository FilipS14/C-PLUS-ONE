#include"Board.h"

Board::Board(uint8_t line, uint8_t column) : //Constructor
	m_line{ line },
	m_column{ column } {
	m_board.resize(line, std::vector<Cell>(column));
}

Board::Board(Board&& other) noexcept : //Move Constructor
	m_line{ std::exchange(other.m_line, 0) },
	m_column{ std::exchange(other.m_column, 0) },
	m_board{ std::move(other.m_board) }
{}

Board& Board::operator=(Board&& other) noexcept //Move Assignament Constructor
{
	if (this != &other) {
		m_line = std::exchange(other.m_line, 0);
		m_column = std::exchange(other.m_column, 0);
		m_board = std::move(other.m_board);
	}
	return *this;
}

Board::Board(const Board& other) : //Copy Constructor
	m_line{ other.m_line },
	m_column{ other.m_column },
	m_board{ other.m_board }
{}

Board& Board::operator=(const Board& other) //Copy Assignament Operator
{
	if (this != &other) {
		m_board.clear();
		m_line = other.m_line;
		m_column = other.m_column;
		m_board = other.m_board;
	}
	return *this;
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


