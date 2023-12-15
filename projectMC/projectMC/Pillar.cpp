#include "Pillar.h"

Pillar::Pillar(QPoint coordinates, Team team) : //Constructor
	m_coordinates{ coordinates },
	m_team{ team }
{}

Pillar::Pillar(Pillar&& other) noexcept // Move Constructor
	: m_coordinates(std::exchange(other.m_coordinates, QPoint())),
	m_team(std::exchange(other.m_team, Team::none))
{}


Pillar& Pillar::operator=(Pillar&& other) noexcept  // Move Assignment Constructor
{
	if (this != &other) {
		m_coordinates = std::exchange(other.m_coordinates, QPoint());
		m_team = std::exchange(other.m_team, Team::none);
	}
	return *this;
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

uint8_t Pillar::getIsConnected() const
{
	return m_isConnected;
}

Team Pillar::getTeam() const {
	return m_team;
}

void Pillar::setCoordX(uint8_t coordX) {
	if (m_coordX > coordX) {
		std::cerr << "Invalid change to pillar\n";
		return;
	}
	m_coordX = coordX;
}

void Pillar::setCoordY(uint8_t coordY) {
	if (m_coordY > coordY) {
		std::cerr << "Invalid change to pillar";
		return;
	}
	m_coordY = coordY;
}

void Pillar::setIsConneted(uint8_t isConnected)
{
	m_isConnected = isConnected; 
}


void Pillar::setTeam(Team team)
{
	m_team = team;
}

void Pillar::isValid(uint8_t coordX, uint8_t coordY)
{
	if (m_coordX > coordX || m_coordY > coordY) {
		std::cerr << "Invalid pillar";
		return;
	}
}