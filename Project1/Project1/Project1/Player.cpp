#include "Player.h"

Player::Player() 
{
	name = "";
	color = "";
}

Player::Player(std::string_view nume, std::string_view culoare) 
{
	name = nume;
	color = culoare;
}




