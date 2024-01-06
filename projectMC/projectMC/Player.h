#pragma once
#include <iostream>
#include <string>

enum class Team
{
	red, black, none
};

class Player
{
private:
	std::string m_name;
	Team m_team;
	int8_t m_numberOfPillars;
	int8_t m_numbersOfBridges;
	bool m_movePillar;

public:
	Player() = default;
	Player(std::string name, Team team);
	~Player() = default;

	//GETTERS
	std::string getName() const;
	Team getTeam() const;
	uint8_t getNumberOfPillars() const;
	uint8_t getNumberOfBridges() const;
	bool getMovePillar() const;

	//SETTERS
	void setName(std::string name);
	void setTeam(Team team);
	void setNumberOfPillars(uint8_t number);
	void setNumberOfBridges(uint8_t number);
	void setMovePillar(bool move);

	//PLAYER HANDLING
	void updateNumberOfPillars(uint8_t number);
	void updateNumberOfBridges(uint8_t number);

	void displayInfo();
};