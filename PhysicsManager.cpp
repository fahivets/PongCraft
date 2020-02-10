/*
**	PhysicsManager.cpp TODO describe magic nambers in globals namespace
*/

#include "PhysicsManager.hpp"

bool	PhysicsManager::checkBallPlayerCollision(Ball::Ptr &ball, std::shared_ptr<Player> const  &player)
{
	if (ball->getX() <= 112 || ball->getX() >= 1087)
		return (PlayerCollision(ball, player));
	return (false);
}

bool	PhysicsManager::blockCollision(Ball::Ptr &ball, Platform::BlockPtr &block)
{
	float ballLeft = ball->getX() - 8;
	float ballRight = ball->getX() + 8;
	float ballTop = ball->getY() - 8;
	float ballBottom = ball->getY() + 8;

	float blockLeft = block->getX();
	float blockRight = block->getX() + 32;
	float blockTop = block->getY();
	float blockBottom = block->getY() + 32;

	if (ballLeft >= blockRight)
	{
		return (false);
	}
	if (ballTop >= blockBottom)
	{
		return (false);
	}
	if ( ballRight <= blockLeft)
	{
		return (false);
	}
	if (ballBottom <= blockTop)
	{
		return (false);
	}
	return (true);
}

bool	PhysicsManager::PlayerCollision(Ball::Ptr &ball, std::shared_ptr<Player> const &player)
{
	auto 	platform = player->getPlatform();
	float	platformHighPoint = platform->getY() - 80;
	float	platformLowPoint = platform->getY() + 80;

	if (ball->getY() < platformHighPoint || ball->getY() > platformLowPoint)	
		return (false);
	for (auto block: platform->getArray())
	{
		if (blockCollision(ball, block))
		{
			if (block->getType() != Block::Type::Invalid)
			{
				if (player->getSlot() == PlayerSlot::Left)
				{
					if (platform->getY() < ball->getY())
						ball->setDir(-ball->getDirX(), 0.75);
					else
						ball->setDir(-ball->getDirX(), -0.75);
				}
				else
				{
					if (platform->getY() < ball->getY())
						ball->setDir(-ball->getDirX(), -0.75);
					else
						ball->setDir(-ball->getDirX(), 0.75);
				}
				break;
			}
		}
	}
	return (false);
}

void	PhysicsManager::ballCollision(Ball::Ptr &ball,
		std::shared_ptr<Player> const &p1, std::shared_ptr<Player> const &p2)
{
	if (ball->getY() <= 8)
		ball->setDirY(ball->getDirY() * -1);
	if (ball->getY() >= 596)
		ball->setDirY(ball->getDirY() * -1);

	if (ball->getX() <= 16)
	{	
		p1->setScore(p1->getScore() + 1);
		ball->reset();
	}
	if (ball->getX() >= 1183)
	{
		p2->setScore(p2->getScore() + 1);	
		ball->reset();
	}
}
