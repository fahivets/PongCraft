/*
** Platform.cpp
** TODO: protect: id, x and y cords;
*/

#include "Platform.hpp"
#include "BlockFactory.hpp"
#include "Globals.hpp"

Platform::Platform()
{
	/*
	for (auto it: m_platformArray)
	{
		it = BlockFactory::createBlock(Block::Type::Invalid);
	}
	*/
}

Platform::Platform(float x, float y) : GameObject(x, y)
{
	float			startY = y - (static_cast<float>(Globals::BLOCK_SIZE) * 2.5);
	float			stepX = x;
	float			stepY = startY;
	unsigned int	block_count = 0;
	
	for (auto it: m_platformArray)
	{
		++block_count;
		setBlockPos(it, stepX, stepY);
		if (block_count % 5 == 0)
		{
			stepX += Globals::BLOCK_SIZE;
			stepY = startY;
		}
		else	
			stepY += Globals::BLOCK_SIZE;
	}
	
	m_platformArray[1] = BlockFactory::createBlock(Block::Type::White);
	m_platformArray[2] = BlockFactory::createBlock(Block::Type::White);
	m_platformArray[3] = BlockFactory::createBlock(Block::Type::White);
}


std::shared_ptr<Block>	Platform::getBlock(unsigned int id) const
{
	if (id < Globals::PLATFORM_MAX_SIZE)
		return (m_platformArray[id]);
	else
		return (nullptr);
}

void					Platform::setBlockPos(std::shared_ptr<Block> block, float x, float y)
{
	block->setX(x);
	block->setY(y);
}

void					Platform::setBlock(unsigned int id, Block::Type type)
{
	m_platformArray[id] = BlockFactory::createBlock(getX(), getY(), type);
}

