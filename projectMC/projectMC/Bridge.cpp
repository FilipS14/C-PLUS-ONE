#include "Bridge.h"

Bridge::Bridge(std::pair<uint8_t, uint8_t> start, std::pair<uint8_t, uint8_t> end) : 
	m_start{ start } , 
	m_end { end }
{}

Bridge::Bridge(uint8_t xStart, uint8_t yStart, uint8_t xEnd, uint8_t yEnd) :
	m_start{ xStart , yStart },
	m_end{ xEnd, yEnd }
{}
