/*
** Ball.cpp
** 
*/

#include "Ball.hpp"
#include "Globals.hpp"

Ball::Ball() : GameObject(Globals::WIN_CENTER_X, Globals::WIN_CENTER_Y), m_dirX(-1), m_dirY(0)
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
	
void	Ball::setPos(float x, float y)
{
	setX(x);
	setY(y);
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

void	Ball::accept(IGameObjectVisitor const &visitor)
{
	visitor.visit(*this);
}

void	Ball::move(float dt)
{
	float speed = 0.5f * dt;
	setX(getX() + m_dirX * speed);
	setY(getY() + m_dirY * speed);
}

void	Ball::startLeft(float x, float y)
{
	setX(x);
	setY(y);
	setDirX(1);
	setDirY(0);
}

void	Ball::startRight(float x, float y)
{
	setX(x);
	setY(y);
	setDirX(-1);
	setDirY(0);
}

void	Ball::reset()
{
	setX(Globals::WIN_CENTER_X);
   	setY(Globals::WIN_CENTER_Y);
	setDirY(0);
}
