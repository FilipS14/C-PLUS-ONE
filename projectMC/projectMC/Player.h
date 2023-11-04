#pragma once
#include <iostream>
#include <string>

class Player
{
private:
	std::string m_name;
	std::string m_color;

public:
	Player() = default;
	Player(std::string name, std::string color);
	~Player() = default;
	std::string getName() const;
	std::string getColor() const;
	void setName(std::string name);
	void setColor(std::string color);
};