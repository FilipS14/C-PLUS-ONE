#pragma once
#include<cstdint>
#include <vector>

class Cell
{
public:
	Cell(bool ocupied, uint8_t x, uint8_t y, bool isMined, bool isBulldozered, std::vector<const Cell*> connectedCells);
	Cell();
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
	bool m_ocupied;
	uint8_t m_x;
	uint8_t m_y;
	bool m_isMined;
	bool m_isBulldozered;
	std::vector<const Cell*> m_connectedCells;
};