#pragma once
#include <iostream>
#include <string_view>
#include <vector>


class Player
{

private:
	std::string_view name;
	std::string_view color;
public:
	Player();

	Player(std::string_view, std::string_view);


};

