#pragma once
#include<iostream>
#include<utility>

class Bridge
{
public:
	Bridge(std::pair<uint8_t, uint8_t> start, std::pair<uint8_t, uint8_t> end);
	Bridge(uint8_t xStart, uint8_t yStart, uint8_t xEnd, uint8_t yEnd);
	~Bridge() = default;

private:
	std::pair<uint8_t, uint8_t>m_start, m_end;
};
