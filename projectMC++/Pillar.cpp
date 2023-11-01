#include "Pillar.h"

uint16_t Pillar::getX()
{
	return x;
}

uint16_t Pillar::getY()
{
	return y;
}

Team Pillar::getTeam()
{
	return team;
}

void Pillar::setX(uint16_t x)
{
	if (coordX > x)
	{
		std::cerr << "Invalid change to pillar";
		return;
	}
	this->x = x;
}

void Pillar::setY(uint16_t y)
{
	if (coordY > y)
	{
		std::cerr << "Invalid change to pillar";
		return;
	}
	this->y = y;
}

void Pillar::setTeam(Team team)
{
	this->team = team;
}

void Pillar::isValid(uint16_t x, uint16_t y)
{
	if (coordX > x || coordY > y)
	{
		std::cerr << "Invalid pillar";
		return;
	}
}
