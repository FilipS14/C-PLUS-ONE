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

Pillar::Pillar(const Pillar& p) : //Copy Constructor
	m_coordinates{ p.m_coordinates },
	m_team{ p.m_team }
{}

Pillar& Pillar::operator=(const Pillar& other) //Copy Assignament Operator
{
	if (this != &other) {
		m_coordinates = other.m_coordinates;
		m_team = other.m_team;
	}
	return *this;
}

//Getteri
QPoint Pillar::getCoordinates() const {
	return m_coordinates;
}

Team Pillar::getTeam() const {
	return m_team;
}

//Setteri
void Pillar::setTeam(Team team)
{
	m_team = team;
}

void Pillar::setCoordinates(const QPoint& coordinates) {
	m_coordinates = coordinates;
}

//Overloading Operators
bool Pillar::operator==(const Pillar& other) const {
	return (m_coordinates == other.m_coordinates) && (m_team == other.m_team);
}

//Pillar manipulation