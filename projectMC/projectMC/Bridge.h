#pragma once
#include<iostream>
#include<utility>
#include <cstdint>
class Bridge
{
public:
	Bridge(std::pair<uint8_t, uint8_t> start, std::pair<uint8_t, uint8_t> end);
	Bridge(uint8_t xStart, uint8_t yStart, uint8_t xEnd, uint8_t yEnd);
	~Bridge() = default;
	std::pair<uint8_t, uint8_t> getStart() const;
	std::pair<uint8_t, uint8_t> getEnd() const;
	void setStart(std::pair<uint8_t, uint8_t> start);
	void setEnd(std::pair<uint8_t, uint8_t> end);
	void setStart(uint8_t xStart, uint8_t yStart);
	void setEnd(uint8_t xEnd, uint8_t yEnd);

private:
	std::pair<uint8_t, uint8_t>m_start, m_end;
};
