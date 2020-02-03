/*
** Movable.cpp
*/

#include "Movable.hpp"


Movable::Movable() : m_x(0), m_y(0)
{}

Movable::Movable(unsigned int x, unsigned int y) : m_x(x), m_y(y)
{}

unsigned int	Movable::getX() const
{
	return (m_x);
}

unsigned int	Movable::getY() const
{
	return (m_y);
}

void			Movable::setX(unsigned int x)
{
	m_x = (x);
}

void			Movable::setY(unsigned int y)
{
	m_y = y;
}
