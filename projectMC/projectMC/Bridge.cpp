#include "Bridge.h"

Bridge::Bridge(std::pair<uint8_t, uint8_t> start, std::pair<uint8_t, uint8_t> end) : 
	m_start{ start } , 
	m_end { end }
{}

Bridge::Bridge(uint8_t xStart, uint8_t yStart, uint8_t xEnd, uint8_t yEnd) :
	m_start{ xStart , yStart },
	m_end{ xEnd, yEnd }
{}

std::pair<uint8_t, uint8_t> Bridge::getStart() const {
	return m_start;
}

std::pair<uint8_t, uint8_t> Bridge::getEnd() const {
	return m_end;
}

void Bridge::setStart(std::pair<uint8_t, uint8_t> start) {
	m_start = start;
}

void Bridge::setEnd(std::pair<uint8_t, uint8_t> end) {
	m_end = end;
}

void Bridge::setStart(uint8_t xStart, uint8_t yStart) {
	m_start = { xStart,yStart };
}

void Bridge::setEnd(uint8_t xEnd, uint8_t yEnd) {
	m_end = { xEnd , yEnd };
}
