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


//SETTERS
void Player::setName(std::string name) {
	m_name = name;
}

void Player::setTeam(Team team) {
	m_team = team;
}

void Player::setNumberOfPillars(uint8_t number)
{
	m_numberOfPillars = number;
}

void Player::setNumberOfBridges(uint8_t number)
{
	m_numbersOfBridges = number;
}

void Player::setMovePillar(bool move)
{
	m_movePillar = move;
}

//PLAYER HANDLING
void Player::updateNumberOfPillars(uint8_t number)
{
	m_numberOfPillars -= number;
}

void Player::updateNumberOfBridges(uint8_t number)
{
	m_numbersOfBridges -= number;
}

void Player::displayInfo()
{
	std::cout << "Player name: " << m_name << std::endl;
	std::cout << "Team: " << static_cast<int>(m_team) << std::endl;
	std::cout << "Number Of Pillars left:" << m_numberOfPillars << std::endl;
	std::cout << "Number of Bridges left:" << m_numbersOfBridges << std::endl;
}
