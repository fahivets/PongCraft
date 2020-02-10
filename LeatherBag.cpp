/*
**	LeatherBag.cpp
*/

#include "LeatherBag.hpp"

LeatherBag::LeatherBag(PlayerSlot slot) : Player(slot)
{}

void		LeatherBag::moveUp()
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
	getPlatform()->setY(getPlatform()->getY() - 16);
	for (auto block: platform)
	{
		block->setY((block->getY() - 16));
	}
}

void		LeatherBag::moveDown()
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
	getPlatform()->setY(getPlatform()->getY() + 16);
	for (auto block: platform)
	{
		block->setY((block->getY() + 16));
	}
}

bool		LeatherBag::isHuman()
{
	return (true);
}
