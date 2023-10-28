#pragma once
#include <cstdint>

class Cell
{
private:

	bool ocupied;
	uint8_t x;
	uint8_t y;
	bool isMined;
	bool isBulldozered;

public:
	Cell();
	Cell(bool, uint8_t, uint8_t, bool, bool);
};



