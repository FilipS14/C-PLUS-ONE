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
	__declspec(dllexport) Player() = default;
	__declspec(dllexport) Player(std::string name, Team team);
	__declspec(dllexport) ~Player() = default;

	//GETTERS
	__declspec(dllexport) std::string getName() const;
	__declspec(dllexport) Team getTeam() const;
	__declspec(dllexport) uint8_t getNumberOfPillars() const;
	__declspec(dllexport) uint8_t getNumberOfBridges() const;
	__declspec(dllexport) bool getMovePillar() const;

	//SETTERS
	__declspec(dllexport) void setName(std::string name);
	__declspec(dllexport) void setTeam(Team team);
	__declspec(dllexport) void setNumberOfPillars(uint8_t number);
	__declspec(dllexport) void setNumberOfBridges(uint8_t number);
	__declspec(dllexport) void setMovePillar(bool move);

	//PLAYER HANDLING
	__declspec(dllexport) void updateNumberOfPillars(uint8_t number);
	__declspec(dllexport) void updateNumberOfBridges(uint8_t number);

	__declspec(dllexport) void displayInfo();
};