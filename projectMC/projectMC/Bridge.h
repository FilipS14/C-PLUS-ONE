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
	Bridge() = default;
	Bridge(QPoint start, QPoint end, QColor color); //Constructor
	Bridge(Bridge&& other) noexcept; //Move Constructor
	Bridge& operator=(Bridge&& other)noexcept; // Move Assignament Constructor
	Bridge(const Bridge& other); //Copy Constructor
	Bridge& operator=(const Bridge& other); //Copy Assignament Operator
	~Bridge() = default; //Destructor

	//Getteri
	QPoint getCoordinatesStart() const;
	QPoint getCoordinatesEnd() const;
	QColor getColor() const;

	//Setteri
	void setCoordinatesStart(const QPoint& start);
	void setCoordinatesEnd(const QPoint& end);
	void setColor(const QColor& color);

private:
	QPoint m_start, m_end;
	QColor m_color;
};