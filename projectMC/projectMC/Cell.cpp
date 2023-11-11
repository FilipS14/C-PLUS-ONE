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
