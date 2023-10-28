#include "Pillar.h"

uint16_t Pillar::getX()
{
	return x;
}

uint16_t Pillar::getY()
{
	return y;
}

Player Pillar::getTeam()
{
	return team;
}

void Pillar::setX(uint16_t x)
{
	this->x = x;
}

void Pillar::setY(uint16_t y)
{
	this->y = y;
}

void Pillar::setTeam(Player team)
{
	this->team = team;
}