#pragma once
#include <iostream>
#include <cstdint>
#include <QPoint>

enum class Team { none, red, black };

class Pillar {

public:
	//rule of 5
	Pillar(QPoint coordinates, Team team); //Constructor
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
	Team getTeam() const;
	
	//Setteri
	void setCoordinates(const QPoint& coordinates);
	void setTeam(Team team);
	void isValid(int32_t x, int32_t y);


private:
	QPoint m_coordinates;
	Team m_team;
};
