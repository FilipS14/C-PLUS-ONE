#pragma once
#include <iostream>
#include<cstdint>

enum class Team { none, red, black };

class Pillar {
private:
	uint8_t m_coordX, m_coordY;
	Team m_team;
public:
	Pillar(uint8_t coordX, uint8_t coordY, Team team);
	Pillar(const Pillar& p);
	~Pillar() = default;
	uint8_t getCoordX() const;
	uint8_t getCoordY() const;
	Team getTeam() const;
	void setCoordX(uint8_t coordX);
	void setCoordY(uint8_t coordY);
	void setTeam(Team team);
	void isValid(uint8_t x, uint8_t y);
};