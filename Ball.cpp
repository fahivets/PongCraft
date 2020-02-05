/*
** Ball.cpp
** TODO set start param
*/

#include "Ball.hpp"
#include "Globals.hpp"

Ball::Ball() : GameObject(Globals::WIN_CENTER_X, Globals::WIN_CENTER_Y)
{}

Ball::Ball(float x, float y) : GameObject(x, y)
{}

float	Ball::getDirX() const
{
	return (m_dirX);
}

float	Ball::getDirY() const
{
	return (m_dirY);
}

float	Ball::getVelocity() const
{
	return (m_velocity);
}
	
void	Ball::setDir(float dirX, float dirY)
{
	m_dirX = dirX;
	m_dirY = dirY;
}

void	Ball::setDirX(float dirX)
{
	m_dirX = dirX;
}

void	Ball::setDirY(float dirY)
{
	m_dirY = dirY;
}

void	Ball::setVelocity(float velocity)
{
	m_velocity = velocity;
}
