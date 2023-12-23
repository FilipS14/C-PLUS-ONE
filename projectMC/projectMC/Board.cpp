#include"Board.h"

//RULE OF FIVE
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

//GETTERS
uint8_t Board::getLine() const {
	return m_line;
}

uint8_t Board::getColumn() const {
	return m_column;
}

std::vector<std::vector<Cell>>& Board::getMatrix()
{
	return m_board;
}

std::unordered_map<QPoint, Pillar, PillarHash>& Board::getPillars()
{
	return m_pillars;
}

std::unordered_map<TwoPoint, Bridge, TwoPointHash>& Board::getBridges() {
	return m_bridges;
}

std::vector<Cell> Board::getRedBase() const
{
	try
	{
		if (m_board.empty())
		{
			throw std::out_of_range("Board is empty");
		}

		const std::vector<Cell>& firstRow = m_board.at(0);

		if (firstRow.empty())
		{
			throw std::out_of_range("First row is empty");
		}

		return firstRow;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return std::vector<Cell>();
	}
}

std::vector<Cell> Board::getBlackBase() const
{
	std::vector<Cell> firstColumn;
	try
	{
		if (m_board.empty())
		{
			throw std::out_of_range("Board is empty");
		}

		for (const auto& row : m_board)
		{
			if (row.empty())
			{
				throw std::out_of_range("Row is empty");
			}

			firstColumn.push_back(row.at(0));
		}
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return std::vector<Cell>();
	}

	return firstColumn;
}

//Setteri
void Board::setLine(uint8_t line) {
	m_line = line;
}

void Board::setColumn(uint8_t column) {
	m_column = column;
}

//Manipulation Matrix
Cell Board::getCell(uint32_t x, uint32_t y) const {
	return m_board.at(x).at(y);
}

void Board::resizeBoard(size_t line, size_t column)
{
	m_line = static_cast<uint8_t>(line);
	m_column = static_cast<uint8_t>(column);
	m_board.resize(m_line, std::vector<Cell>(m_column));
}


