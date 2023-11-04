#include "Pillar.h"

Pillar::Pillar(uint8_t coordX, uint8_t coordY, Team team) :
	m_coordX{ coordX },
	m_coordY{ coordY },
	m_team{ team } {
}

Pillar::Pillar(const Pillar& p) :
	m_coordX{ p.m_coordX },
	m_coordY{ p.m_coordY },
	m_team{ p.m_team } {
}

uint8_t Pillar::getCoordX() const {
	return m_coordX;
}

uint8_t Pillar::getCoordY() const {
	return m_coordY;
}

Team Pillar::getTeam() const {
	return m_team;
}