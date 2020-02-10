/*
**	Player.cpp
*/

#include "Player.hpp"

Player::Player()
{}

Player::Player(PlayerSlot slot) : m_score(0), m_slot(slot)
{
	if (slot == PlayerSlot::Left)
		m_platform = std::make_shared<Platform>(16, 304, slot);
	else
		m_platform = std::make_shared<Platform>(1183, 304, slot);
}

Player::~Player()
{}
//  нужно проверять выход за экран, или тут или в колизии
void		Player::moveUp()
{
	const auto platform = m_platform->getArray();
	for (auto block: platform)
	{
		if (block->getType() != Block::Type::Invalid)
		{
			if (block->getY() <= 0)
				return ;
		}
	}
	m_platform->setY(m_platform->getY() - 16);
	for (auto block: platform)
	{
		block->setY((block->getY() - 16));
	}
}

void		Player::moveDown()
{
	const auto platform = m_platform->getArray();
	for (auto block: platform)
	{
		if (block->getType() != Block::Type::Invalid)
		{
			if (block->getY() + 32  >= 604)
				return ;
		}
	}
	m_platform->setY(m_platform->getY() + 16);
	for (auto block: platform)
	{
		block->setY((block->getY() + 16));
	}
}

int			Player::getScore() const
{
	return (m_score);
}

PlayerSlot	Player::getSlot() const
{
	return (m_slot);
}
void		Player::setScore(int score)
{
	m_score = score;
}

void		Player::setSlot(PlayerSlot slot)
{
	m_slot = slot;
}

std::shared_ptr<Platform>	Player::getPlatform() const
{
	return (m_platform);
}

void					Player::accept(IGameObjectVisitor const &visitor)
{
	visitor.visit(*this);
}
