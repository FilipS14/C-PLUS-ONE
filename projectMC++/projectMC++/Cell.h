#pragma once
#include <cstdint>

class Cell
{
private:

	bool m_ocupied;
	uint8_t m_x;
	uint8_t m_y;
	bool m_isMined;
	bool m_isBulldozered;

public:
	Cell();
	Cell(bool, uint8_t, uint8_t, bool, bool);

	bool este_ocupat();
};
