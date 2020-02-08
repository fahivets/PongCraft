/*
**	Player.cpp
*/

#include "Player.hpp"

#include <iostream> // TODO del!

Player::Player()
{}

Player::Player(Player::Slot slot)
{
	if (slot == Player::Slot::Left)
		m_platform = std::make_shared<Platform>(16, 300);
	else
		m_platform = std::make_shared<Platform>(1184 , 300);
}

Player::~Player()
{}
//  нужно проверять выход за экран, или тут или в колизии
void		Player::moveUp()
{
	std::cout << "[INFO] Player move up" << std::endl;
	const auto platform = m_platform->getArray();
	for (auto &block: platform)
	{
		block->setY((block->getY() - 1));
	}
}

void		Player::moveDown()
{
	std::cout << "[INFO] Player move down" << std::endl;
	
	const auto platform = m_platform->getArray();
	for (auto &block: platform)
	{
		block->setY((block->getY() + 1));
	}
}

std::shared_ptr<Platform>	Player::getPlatform() const
{
	return (m_platform);
}
