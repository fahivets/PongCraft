/*
**	AIPlayer.cpp
*/

#include "AIPlayer.hpp"
#include "Globals.hpp"
#include <random>

AIPlayer::AIPlayer(PlayerSlot slot) : Player(slot), m_step(1.0f)
{}

bool	AIPlayer::isHuman()
{
	return (false);
}

void		AIPlayer::moveUp()
{
	const auto platform = getPlatform()->getArray();
	for (auto block: platform)
	{
		if (block->getType() != Block::Type::Invalid)
		{
			if (block->getY() <= 0)
				return ;
		}
	}

	getPlatform()->setY(getPlatform()->getY() - m_step);
	for (auto block: platform)
	{
		block->setY((block->getY() - m_step));
	}
}

void		AIPlayer::moveDown()
{
	const auto platform = getPlatform()->getArray();
	for (auto block: platform)
	{
		if (block->getType() != Block::Type::Invalid)
		{
			if (block->getY() + 32  >= 604)
				return ;
		}
	}
	getPlatform()->setY(getPlatform()->getY() + m_step);
	for (auto block: platform)
	{
		block->setY((block->getY() + m_step));
	}
}

void	AIPlayer::iqTest(Ball::Ptr const &ball)
{
	const auto platform = getPlatform();

	std::default_random_engine godOfRandom;
	std::uniform_int_distribution<float> distribution(0.5f,1.5f);
	float luck = distribution(godOfRandom);

	if (ball->getX() < Globals::WIN_CENTER_X)
		m_step = 0.5f;
	else
		m_step = luck;
	if (platform->getY() > ball->getY())
		moveUp();
	else
		moveDown();
}
