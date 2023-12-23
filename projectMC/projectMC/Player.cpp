#include "Player.h"

Player::Player(std::string name, Team team) :
	m_name{ name },
	m_team{ team }
{
	m_numberOfPillars = 50;
	m_numbersOfBridges = 50;
	m_movePillar = false;
}

//GETTERS
std::string Player::getName() const
{
	return m_name;
}

Team Player::getTeam() const
{
	return m_team;
}

uint8_t Player::getNumberOfPillars() const
{
	return m_numberOfPillars;
}

uint8_t Player::getNumberOfBridges() const
{
	return m_numbersOfBridges;
}

bool Player::getMovePillar() const
{
	return m_movePillar;
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

void Player::setTurn(bool turn)
{
	m_player1_turn = turn;
}

bool Player::getTurn() const
{
	return m_player1_turn;
}
