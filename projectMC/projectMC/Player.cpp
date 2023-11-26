#include"Player.h"

Player::Player(std::string nume, std::string culoare, bool status, bool player1_turn) :
	m_name{ nume },
	m_color{ culoare } ,
	m_status{ status },
	m_player1_turn{player1_turn}
{}

std::string Player::getName() const {
	return m_name;
}

std::string Player::getColor() const {
	return m_color;
}

bool Player::get_status() const
{
	return false;
}

void Player::setName(std::string name) {
	m_name = name;
}

void Player::setColor(std::string color) {
	m_color = color;
}

void Player::displaiInfo()
{
	std::cout << "Player information: " << "Name: " << m_name << " | Color: " << m_color << std::endl;
}

bool Player::player_won()
{
	return m_status;
}
