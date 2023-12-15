#include "Bridge.h"

Bridge::Bridge(QPoint start, QPoint end) : //Constructor
	m_start{ start },
	m_end{ end }
{}

Bridge::Bridge(Bridge&& other) noexcept //Move Constructor
	: m_start{ std::move(other.m_start) },
	m_end{ std::move(other.m_end) }
{}

Bridge& Bridge::operator=(Bridge&& other) noexcept //Move Assignment Operator
{
	if (this != &other)
	{
		m_start = std::move(other.m_start);
		m_end = std::move(other.m_end);
	}
	return *this;
}

Bridge::Bridge(const Bridge& other) //Copy Constructor
	: m_start{ other.m_start },
	m_end{ other.m_end }
{}

Bridge& Bridge::operator=(const Bridge& other) //Copy Assignment Operator 
{
	if (this != &other) {
		m_start = other.m_start;
		m_end = other.m_end;
	}
	return *this;
}
