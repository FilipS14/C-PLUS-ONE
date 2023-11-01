#include "Cell.h"

Cell::Cell() : m_ocupied{ false }, m_x{ 0 }, m_y{ 0 }, m_isMined{ false }, m_isBulldozered{ false } {};

Cell::Cell(bool ocupat, uint8_t x, uint8_t y, bool este_minat, bool este_lovit) : m_ocupied{ ocupat }, m_x{ x }, m_y{ y }, m_isMined{ este_minat }, m_isBulldozered{ este_lovit } {}

bool Cell::este_ocupat() { return false; }

