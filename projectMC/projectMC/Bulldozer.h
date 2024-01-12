#pragma once
#include <QPoint>
#include <random>

class Bulldozer
{

public:
	//CONSTRUCTOR
	Bulldozer() = default;

	//GETTERS
	uint8_t getX();
	uint8_t getY();

	//SETTERS
	void setX(uint8_t x);
	void setY(uint8_t y);

	//GENERATE START POSITION
	void generateStart();

private:

	QPoint m_bulldozer;
	uint8_t m_x;
	uint8_t m_y;

};

