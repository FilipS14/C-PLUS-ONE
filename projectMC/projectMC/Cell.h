#pragma once
#include<cstdint>

class Cell
{
public:
	Cell(bool ocupied, uint8_t x, uint8_t y, bool isMined, bool isBulldozered);
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

private:
	bool m_ocupied;
	uint8_t m_x;
	uint8_t m_y;
	bool m_isMined;
	bool m_isBulldozered;
};