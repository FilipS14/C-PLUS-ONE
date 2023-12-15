#pragma once
#include <cstdint>
#include <vector>
#include <QPoint>
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

	bool getOcupier() const;
	uint8_t getX() const;
	uint8_t getY() const;
	bool getIsMined() const;
	bool getIsBulldozered() const;
	void setOcupied(bool ocupied);
	void setX(uint8_t x);
	void setY(uint8_t y);
	void setMined();
	void setBulldozered();
	void clearCell();
	void resetCell();
	bool emptyCell();
	bool safeCell();
	bool isConnectedTo(const Cell& cell)const;
	Cell& operator=(const Cell& cell);

private:
private:
	uint8_t m_line;
	uint8_t m_column;
	QPoint m_coordinates;
	bool m_ocupied;
	bool m_isMined;
	bool m_isBulldozered;
};