#include"Cell.h"

Cell::Cell(bool ocupied, QPoint coordinates, uint8_t line, uint8_t column, bool isMined, bool isBulldozered) : //Constructor
	m_ocupied{ ocupied },
	m_coordinates{ coordinates },
	m_line{ line },
	m_column{ column },
	m_isMined{ isMined },
	m_isBulldozered{ isBulldozered }
{}

Cell::Cell() : //Constructor
	m_ocupied{ false },
	m_isMined{ false },
	m_isBulldozered{ false }
{}

Cell::Cell(Cell&& other) noexcept // Move Constructor
	: m_ocupied{ other.m_ocupied },
	m_coordinates{ other.m_coordinates },
	m_line{ other.m_line },
	m_column{ other.m_column },
	m_isMined{ other.m_isMined },
	m_isBulldozered{ other.m_isBulldozered }
{
	other.m_ocupied = false;
	other.m_coordinates = { 0,0 };
	other.m_line = 0;
	other.m_column = 0;
	other.m_isMined = false;
	other.m_isBulldozered = false;
}

bool Cell::getOcupier() const {
	return m_ocupied;
}

uint8_t Cell::getX() const {
	return m_x;
}

uint8_t Cell::getY() const {
	return m_y;
}

bool Cell::getIsMined() const {
	return m_isMined;
}

bool Cell::getIsBulldozered() const {
	return m_isBulldozered;
}

void Cell::setOcupied(bool ocupied)
{
	m_ocupied = ocupied;
}

void Cell::setX(uint8_t x) {
	m_x = x;
}

void Cell::setY(uint8_t y) {
	m_y = y;
}

void Cell::setMined()
{
	m_isMined = true;
}

void Cell::setBulldozered()
{
	m_isBulldozered = true;
}

void Cell::clearCell()
{
	m_ocupied = false; 
	m_isMined = false; 
	m_isBulldozered = false; 
}

void Cell::resetCell()
{
	m_ocupied = false;
	m_isMined = false;
	m_isBulldozered = false;
}

bool Cell::emptyCell()
{
	return m_ocupied == false;
}

bool Cell::safeCell()
{
	return (!m_isMined && !m_isBulldozered);
}

bool Cell::isConnectedTo(const Cell& cell) const
{
	for (const Cell* connected_cell : m_connectedCells)
	{
		if (connected_cell == &cell)
		{
			return true;
		}
	}
	return false;
}


Cell& Cell::operator=(const Cell& cell)
{
	if (this != &cell)
	{
		m_x = cell.m_x;
		m_y = cell.m_y;
		m_isBulldozered = cell.m_isBulldozered;
		m_isMined = cell.m_isMined;
		m_ocupied = cell.m_ocupied;
	}
	return *this;
}