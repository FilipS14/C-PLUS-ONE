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

	uint16_t getX();
	uint16_t getY();
	Team getTeam();
	void setX(uint16_t x);
	void setY(uint16_t y);
	void setTeam(Team team);
};