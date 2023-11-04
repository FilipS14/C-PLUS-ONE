#include"Player.h"

Player::Player(std::string nume, std::string culoare) :
	m_name{ nume },
	m_color{ culoare } {
}

std::string Player::getName() const {
	return m_name;
}

std::string Player::getColor() const {
	return m_color;
}

void Player::setName(std::string name) {
	m_name = name;
}

void Player::setColor(std::string color) {
	m_color = color;
}