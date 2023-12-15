#pragma once
#include<iostream>
#include <cstdint>
#include <QPoint>

class Bridge
{
public:
	//rule of 5
	Bridge() = default;
	Bridge(QPoint start, QPoint end); //Constructor
	Bridge(Bridge&& other) noexcept; //Move Constructor
	Bridge& operator=(Bridge&& other)noexcept; // Move Assignament Constructor
	Bridge(const Bridge& other); //Copy Constructor
	Bridge& operator=(const Bridge& other); //Copy Assignament Operator
	~Bridge() = default; //Destructor

	//Getteri
	QPoint getCoordinatesStart() const;
	QPoint getCoordinatesEnd() const;

	//Setteri
	void setCoordinatesStart(const QPoint& start);
	void setCoordinatesEnd(const QPoint& end);

private:
	QPoint m_start, m_end;
};
