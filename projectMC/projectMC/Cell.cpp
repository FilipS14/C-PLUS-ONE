#include"Cell.h"
#include "Board.h"

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

Cell& Cell::operator=(Cell&& other) noexcept // Move Assignment Operator
{
	if (this != &other) {
		m_ocupied = false;
		m_coordinates = { 0,0 };
		m_line = 0;
		m_column = 0;
		m_isMined = false;
		m_isBulldozered = false;

		m_ocupied = other.m_ocupied;
		m_coordinates = other.m_coordinates;
		m_line = other.m_line;
		m_column = other.m_column;
		m_isMined = other.m_isMined;
		m_isBulldozered = other.m_isBulldozered;

		other.m_ocupied = false;
		other.m_coordinates = { 0,0 };
		other.m_line = 0;
		other.m_column = 0;
		other.m_isMined = false;
		other.m_isBulldozered = false;
	}
	return *this;
}

Cell::Cell(const Cell& other) //Copy Constructor
	: m_ocupied{ other.m_ocupied },
	m_coordinates{ other.m_coordinates },
	m_line{ other.m_line },
	m_column{ other.m_column },
	m_isMined{ other.m_isMined },
	m_isBulldozered{ other.m_isBulldozered }
{}

Cell& Cell::operator=(const Cell& other) //Copy Assignment Operator
{
	if (this != &other) {
		m_ocupied = other.m_ocupied;
		m_coordinates = other.m_coordinates;
		m_line = other.m_line;
		m_column = other.m_column;
		m_isMined = other.m_isMined;
		m_isBulldozered = other.m_isBulldozered;
	}
	return *this;
}

//Getteri
bool Cell::getOcupier() const {
	return m_ocupied;
}

bool Cell::getIsMined() const {
	return m_isMined;
}

bool Cell::getIsBulldozered() const {
	return m_isBulldozered;
}

QPoint Cell::getCoordinates() const
{
	return m_coordinates;
}

uint8_t Cell::getLine() const
{
	return m_line;
}

uint8_t Cell::getColumn() const
{
	return m_column;
}

//Setteri
void Cell::setMined(bool status)
{
	m_isMined = status;
}

void Cell::setBulldozered(bool status)
{
	m_isBulldozered = status;
}

void Cell::setOcupied(bool status)
{
	m_ocupied = status;
}

void Cell::setCoordinates(const QPoint& coordinates) {
	m_coordinates = coordinates;
}

void Cell::setLine(const uint8_t& line)
{
	m_line = line;
}

void Cell::setColumn(const uint8_t& column)
{
	m_column = column;
}


// Metode joc
void Cell::clearCell()
{
	m_ocupied = false; 
	m_isMined = false; 
	m_isBulldozered = false; 
	m_line = 0; 
	m_column = 0; 
	m_coordinates = QPoint(); 
}

std::vector<QPoint> Cell::getNeighborCoordinates() const noexcept
{
	std::vector<QPoint> neighbors;

	for (uint8_t dx = -1; dx <= 1; ++dx) 
	{
		for (uint8_t dy = -1; dy <= 1; ++dy)
		{
			if (dx == 0 && dy == 0) 
			{
				continue;
			}

			QPoint neighbor = m_coordinates + QPoint(dx, dy);

			neighbors.push_back(neighbor);
		}
	}
	return neighbors;
}

void Cell::bulldozerTurn(std::vector<Cell>& board) 
{
	if (isBulldozeristHere()) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 1);
		int result = dis(gen);

		if (result == 0) {
			std::vector<std::unique_ptr<Cell>> pillars;

			for (const auto& neighborCoord : getNeighborCoordinates())
			{
				const int index = neighborCoord.x() * getLine() + neighborCoord.y();
				if (index >= 0 && index < board.size()) {
					Cell& neighborCell = board[index];
					if (neighborCell.getIsMined() && !neighborCell.getIsBulldozered()) 
					{
						pillars.push_back(std::make_unique<Cell>(neighborCell));
					}
				}
			}

			if (!pillars.empty()) 
			{
				std::shuffle(pillars.begin(), pillars.end(), gen);

				std::unique_ptr<Cell>& pillarToDestroy = pillars.front();
				pillarToDestroy->clearCell();
				setCoordinates(pillarToDestroy->getCoordinates());
				pillarToDestroy->setBulldozered(true);
			}
		}

		else 
		{
			std::vector<QPoint> emptyCells;

			for (const auto& neighborCoord : getNeighborCoordinates())
			{
				const int index = neighborCoord.x() * getLine() + neighborCoord.y();
				if (index >= 0 && index < board.size()) 
				{
					Cell& neighborCell = board[index];
					if (!neighborCell.getOcupier() && !neighborCell.getIsMined()) 
					{
						emptyCells.push_back(neighborCell.getCoordinates());
					}
				}
			}

			if (!emptyCells.empty())
			{
				std::shuffle(emptyCells.begin(), emptyCells.end(), gen);

				QPoint newCoordinates = emptyCells.front();
				setCoordinates(newCoordinates);
			}
		}
	}
}

bool Cell::isBulldozeristHere() const 
{
	return m_ocupied && !m_isMined && !m_isBulldozered;
}

void Cell::placeBulldozerist(std::vector<Cell>& cells)
{
	std::vector<size_t> emptyCellIndices;

	for (size_t i = 0; i < cells.size(); ++i) 
	{
		if (!cells[i].getOcupier() && !cells[i].getIsMined())
		{
			emptyCellIndices.push_back(i);
		}
	}

	if (!emptyCellIndices.empty()) 
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<size_t> dis(0, emptyCellIndices.size() - 1);

		size_t randomIndex = dis(gen);


		cells[emptyCellIndices[randomIndex]].setOcupied(true);
	}
}

bool Cell::isEmpty() const
{
	return !m_ocupied && !m_isMined;
}

