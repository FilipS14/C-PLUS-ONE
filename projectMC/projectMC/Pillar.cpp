#include "Pillar.h"

Pillar::Pillar(QPoint coordinates, QColor color) : //Constructor
	m_coordinates{ coordinates },
	m_color{ color }
{}

Pillar::Pillar(Pillar&& other) noexcept // Move Constructor
	: m_coordinates(std::exchange(other.m_coordinates, QPoint())),
	m_color(std::exchange(other.m_color, other.m_color))
{}


Pillar& Pillar::operator=(Pillar&& other) noexcept  // Move Assignment Constructor
{
	if (this != &other) {
		m_coordinates = std::exchange(other.m_coordinates, QPoint());
		m_color = std::exchange(other.m_color, other.m_color);
	}
	return *this;
}

Pillar::Pillar(const Pillar& p) : //Copy Constructor
	m_coordinates{ p.m_coordinates },
	m_color{ p.m_color }
{}

Pillar& Pillar::operator=(const Pillar& other) //Copy Assignament Operator
{
	if (this != &other) {
		m_coordinates = other.m_coordinates;
		m_color = other.m_color;
	}
	return *this;
}

//GETTERS
QPoint Pillar::getCoordinates() const {
	return m_coordinates;
}

QColor Pillar::getColor() const
{
	return m_color;
}


//SETTERS
void Pillar::setColor(QColor color)
{
	m_color = color;
}

void Pillar::setCoordinates(const QPoint& coordinates) {
	m_coordinates = coordinates;
}

//OVERLOADING OPERATORS
bool Pillar::operator==(const Pillar& other) const {
	return m_coordinates == other.m_coordinates;
}

