#include "Bridge.h"

Bridge::Bridge(QPoint start, QPoint end, QColor color) : //Constructor
    m_start{ start },
    m_end{ end },
    m_color{ color }
{}

Bridge::Bridge(Bridge&& other) noexcept //Move Constructor
    : m_start{ std::move(other.m_start) },
    m_end{ std::move(other.m_end) },
    m_color{ std::move(other.m_color) }
{}

Bridge& Bridge::operator=(Bridge&& other) noexcept //Move Assignment Operator
{
    if (this != &other)
    {
        m_start = std::move(other.m_start);
        m_end = std::move(other.m_end);
        m_color = std::move(other.m_color);
    }
    return *this;
}

Bridge::Bridge(const Bridge& other) //Copy Constructor
    : m_start{ other.m_start },
    m_end{ other.m_end },
    m_color{ other.m_color }
{}

Bridge& Bridge::operator=(const Bridge& other) //Copy Assignment Operator 
{
    if (this != &other) {
        m_start = other.m_start;
        m_end = other.m_end;
        m_color = other.m_color;
    }
    return *this;
}

//Getteri
QPoint Bridge::getCoordinatesStart() const
{
    return m_start;
}

QPoint Bridge::getCoordinatesEnd() const
{
    return m_end;
}

QColor Bridge::getColor() const
{
    return m_color;
}

//Setteri
void Bridge::setCoordinatesStart(const QPoint& start)
{
    m_start = start;
}

void Bridge::setCoordinatesEnd(const QPoint& end)
{
    m_end = end;
}

void Bridge::setColor(const QColor& color)
{
    m_color = color;
}
