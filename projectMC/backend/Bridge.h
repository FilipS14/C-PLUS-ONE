#pragma once
#include<iostream>
#include<utility>
#include <cstdint>
#include <QPoint>
#include <QColor>
#include "Pillar.h"

class Bridge
{
public:
	//rule of 5
	__declspec(dllexport) Bridge() = default;
	__declspec(dllexport) Bridge(QPoint start, QPoint end, QColor color); //Constructor
	__declspec(dllexport) Bridge(Bridge&& other) noexcept; //Move Constructor
	__declspec(dllexport) Bridge& operator=(Bridge&& other)noexcept; // Move Assignament Constructor
	__declspec(dllexport) Bridge(const Bridge& other); //Copy Constructor
	__declspec(dllexport) Bridge& operator=(const Bridge& other); //Copy Assignament Operator
	__declspec(dllexport) ~Bridge() = default; //Destructor

	//Getteri
	__declspec(dllexport) QPoint getCoordinatesStart() const;
	__declspec(dllexport) QPoint getCoordinatesEnd() const;
	__declspec(dllexport) QColor getColor() const;

	//Setteri
	__declspec(dllexport) void setCoordinatesStart(const QPoint& start);
	__declspec(dllexport) void setCoordinatesEnd(const QPoint& end);
	__declspec(dllexport) void setColor(const QColor& color);

private:
	QPoint m_start, m_end;
	QColor m_color;
};