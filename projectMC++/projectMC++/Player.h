#pragma once
#include <iostream>
#include <string>

class Player
{
private:
	std::string m_name;
	std::string m_color;

public:
	Player();

	Player(std::string, std::string);
};

