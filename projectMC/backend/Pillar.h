#pragma once
#include <iostream>
#include <cstdint>
#include <QPoint>
#include <QColor>

class Pillar {

public:
	//rule of 5
	__declspec(dllexport) Pillar(QPoint coordinates, QColor color); //Constructor
	__declspec(dllexport) Pillar() = default; //Constructor
	__declspec(dllexport) Pillar(Pillar&& other) noexcept; //Move Constructor
	__declspec(dllexport) Pillar& operator=(Pillar&& other) noexcept; //Move Assignament Constructor
	__declspec(dllexport) Pillar(const Pillar& p); //Copy Constructor
	__declspec(dllexport) Pillar& operator=(const Pillar& other); //Copy Assignament Oprator 
	__declspec(dllexport) ~Pillar() = default; //Destructor

	//overloading operators
	__declspec(dllexport) bool operator==(const Pillar& other) const;

	//Getteri
	__declspec(dllexport) QPoint getCoordinates() const;
	__declspec(dllexport) QColor getColor() const;

	//Setteri
	__declspec(dllexport) void setCoordinates(const QPoint& coordinates);
	__declspec(dllexport) void setColor(QColor color);

private:
	QPoint m_coordinates;
	QColor m_color;
};
