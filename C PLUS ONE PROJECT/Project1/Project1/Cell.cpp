#include "Cell.h"

Cell::Cell()
{
	ocupied = false;
	x = 0;
	y = 0; //Default va lua coordonatele coltului stanga jos
	isMined = false;
	isBulldozered = false;

}

Cell::Cell(bool ocupat, uint8_t x, uint8_t y, bool este_minat, bool este_lovit)
{
	ocupied = ocupat;
	this->x = x;
	this->y = y;
	isMined = este_minat;
	isBulldozered = este_lovit;
}
