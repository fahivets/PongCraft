/*
** Platform.cpp 
** 
*/

#include "Platform.hpp"
#include "BlockFactory.hpp"

Platform::Platform()
{
	
	for (auto &it: m_platformArray)
	{
		it = BlockFactory::createBlock(Block::Type::Invalid);
	}
	
}

Platform::Platform(float x, float y, PlayerSlot slot) : GameObject(x, y)
{
	if (slot == PlayerSlot::Left)
		createLeftPlayer(x, y);
	else
		createRightPlayer(x, y);
}

void	Platform::createLeftPlayer(float x, float y)
{
	float			startY = y - (Globals::PLATFORM_H / 2);
	float			stepX = x;
	float			stepY = startY;
	unsigned int	block_count = 0;
	
	for (auto &it: m_platformArray)
	{
		++block_count;
		it = BlockFactory::createBlock(stepX, stepY, Block::Type::Invalid);
		if (block_count % 5 == 0)
		{
			stepX += Globals::BLOCK_SIZE;
			stepY = startY;
		}
		else	
			stepY += Globals::BLOCK_SIZE;
	}

	m_platformArray[1]->setType(Block::Type::White);
	m_platformArray[2]->setType(Block::Type::White);
	m_platformArray[3]->setType(Block::Type::White);
	m_platformArray[5]->setType(Block::Type::White);
	m_platformArray[9]->setType(Block::Type::White);
}

void	Platform::createRightPlayer(float x, float y)
{
	float			startY = y - (Globals::PLATFORM_H / 2);
	float			stepX = x - 96;
	float			stepY = startY;
	unsigned int	block_count = 0;
	
	for (auto &it: m_platformArray)
	{
		++block_count;
		it = BlockFactory::createBlock(stepX, stepY, Block::Type::Invalid);
		if (block_count % 5 == 0)
		{
			stepX += Globals::BLOCK_SIZE;
			stepY = startY;
		}
		else	
			stepY += Globals::BLOCK_SIZE;
	}
	
	m_platformArray[11]->setType(Block::Type::White);
	m_platformArray[12]->setType(Block::Type::White);
	m_platformArray[13]->setType(Block::Type::White);
}

std::shared_ptr<Block>	Platform::getBlock(unsigned int id) const
{
	if (id < Globals::PLATFORM_MAX_SIZE)
		return (m_platformArray[id]);
	else
		return (nullptr);
}

std::array<std::shared_ptr<Block>, Globals::PLATFORM_MAX_SIZE>	Platform::getArray() const
{
	return (m_platformArray);
}

void					Platform::setBlock(unsigned int id, Block::Type type)
{
	m_platformArray[id] = BlockFactory::createBlock(type);
}

void					Platform::accept(IGameObjectVisitor const &visitor)
{
	visitor.visit(*this);
}
