#pragma once
#include <cstdint>
#include <vector>
#include <QPoint>
#include <random>

class Cell
{
public:
	//rules of 5
	Cell(bool ocupied, QPoint coordinates, uint8_t line, uint8_t column, bool isMined, bool isBulldozered);//Constructor
	Cell();//Constructor
	Cell(Cell&& other) noexcept; //Move Constructor
	Cell& operator=(Cell&& other)noexcept; // Move Assignament Constructor
	Cell(const Cell& other); //Copy Constructor
	Cell& operator=(const Cell& other); //Copy Assignament Operator
	~Cell() = default;

	//getteri
	bool getOcupier() const;
	bool getIsMined() const;
	bool getIsBulldozered() const;
	bool isEmpty() const;
	QPoint getCoordinates() const;
	uint8_t getLine() const;
	uint8_t getColumn() const;

	//setteri
	void setOcupied(bool status);
	void setMined(bool status);
	void setBulldozered(bool status);
	void setCoordinates(const QPoint& coordinates);
	void setLine(const uint8_t& line);
	void setColumn(const uint8_t& column);

	//Game methods
	void clearCell();
	std::vector<QPoint> getNeighborCoordinates() const noexcept;
	void bulldozerTurn(std::vector<Cell>& board);
	bool isBulldozeristHere();
	void placeBulldozerist(std::vector<Cell>& cells);

private:
	uint8_t m_line;
	uint8_t m_column;
	QPoint m_coordinates;
	bool m_ocupied;
	bool m_isMined;
	bool m_isBulldozered;
};