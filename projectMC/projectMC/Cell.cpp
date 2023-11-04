#include"Cell.h"

Cell::Cell(bool ocupied, uint8_t x, uint8_t y, bool isMined, bool isBulldozered) :
	m_ocupied{ ocupied },
	m_x{ x },
	m_y{ y },
	m_isMined{ isMined },
	m_isBulldozered{ isBulldozered } {
}

Cell::Cell() :
	m_ocupied{ false },
	m_x{ 0 },
	m_y{ 0 },
	m_isMined{ false },
	m_isBulldozered{ false } {
}