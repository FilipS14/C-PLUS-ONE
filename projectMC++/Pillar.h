#pragma once
#include <iostream>
#include <stdint.h>

enum class Team {none , red, black};

class Pillar {
private:
	uint16_t coordX, coordY;
	Team team;
public:
	Pillar(uint16_t coordX, uint16_t coordY, Team team) :
		coordX(coordX), coordY(coordY), team(team) { }

	Pillar(const Pillar& p) :
		coordX([p.coordX), coordY(p.coordY), team(team) { }

	~Pillar() { }
};