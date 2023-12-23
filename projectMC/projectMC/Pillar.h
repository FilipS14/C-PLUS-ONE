#pragma once
#include <iostream>
#include <cstdint>
#include <QPoint>
#include <QColor>

class Pillar {

public:
	//rule of 5
	Pillar(QPoint coordinates, QColor color); //Constructor
	Pillar() = default; //Constructor
	Pillar(Pillar&& other) noexcept; //Move Constructor
	Pillar& operator=(Pillar&& other) noexcept; //Move Assignament Constructor
	Pillar(const Pillar& p); //Copy Constructor
	Pillar& operator=(const Pillar& other); //Copy Assignament Oprator 
	~Pillar() = default; //Destructor

	//overloading operators
	bool operator==(const Pillar& other) const;

	//Getteri
	QPoint getCoordinates() const;
	QColor getColor() const;

	//Setteri
	void setCoordinates(const QPoint& coordinates);
	void setColor(QColor color);

private:
	QPoint m_coordinates;
	QColor m_color;
};
