#pragma once
#include <iostream>
#include <string>

class Player
{
private:
	std::string m_name;
	std::string m_color;
	bool m_status;
	bool m_player1_turn;

public:
	Player() = default;
	Player(std::string name, std::string color, bool status, bool player1_turn);
	~Player() = default;
	std::string getName() const;
	std::string getColor() const;
	bool get_status() const;
	void setName(std::string name);
	void setColor(std::string color);
	void displaiInfo();
	bool player_won();

};