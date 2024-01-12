#include "Bulldozer.h"

Bulldozer::Bulldozer(const Bulldozer& b) : m_bulldozer{ b.m_bulldozer } {}

uint8_t Bulldozer::getX()
{
	return m_x;
}

uint8_t Bulldozer::getY()
{
	return m_y;
}

void Bulldozer::setX(uint8_t x)
{
	m_x = x;
}

void Bulldozer::setY(uint8_t y)
{
	m_y = y;
}

void Bulldozer::generateStart()
{
    std::uniform_int_distribution<uint8_t> distX(0, 22); 
    std::uniform_int_distribution<uint8_t> distY(0, 22); 

    std::mt19937 random(std::random_device{}()); 

    uint8_t x = distX(random);
    uint8_t y = distY(random);

    m_bulldozer.setX(x);
    m_bulldozer.setY(y);

}
