/*
** GameObject.cpp
*/

#include "GameObject.hpp"


GameObject::GameObject() : m_x(0), m_y(0)
{}

GameObject::GameObject(float x, float y) : m_x(x), m_y(y)
{}

GameObject::GameObject(GameObject const &src) : m_x(src.m_x), m_y(src.m_y)
{}

GameObject	&GameObject::operator=(GameObject const &rhs)
{
	if (this != &rhs)
	{
		m_x = rhs.m_x;
		m_y = rhs.m_y;
	}
	return (*this);
}

float		GameObject::getX() const
{
	return (m_x);
}

float		GameObject::getY() const
{
	return (m_y);
}

void		GameObject::setX(float x)
{
	m_x = x;
}

void		GameObject::setY(float y)
{
	m_y = y;
}
