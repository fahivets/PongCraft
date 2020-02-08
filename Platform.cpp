/*
** Platform.cpp 
** TODO: protect: id, x and y cords; change setBlock? how thake array?
*/

#include "Platform.hpp"
#include "BlockFactory.hpp"


#include <iostream> // DELL

Platform::Platform()
{
	
	for (auto &it: m_platformArray)
	{
		it = BlockFactory::createBlock(Block::Type::Invalid);
	}
	
}

Platform::Platform(float x, float y) : GameObject(x, y)
{
	float			startY = y - (static_cast<float>(Globals::BLOCK_SIZE) * 2.5);
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

void					Platform::setBlockPos(std::shared_ptr<Block> block, float x, float y)
{
	block->setX(x);
	block->setY(y);
}

/*	think here	*/
void					Platform::setBlock(unsigned int id, Block::Type type)
{
	m_platformArray[id] = BlockFactory::createBlock(type);
}

void					Platform::accept(IGameObjectVisitor const &visitor)
{
	visitor.visit(*this);
}



/* dell after	*/
void	Platform::print()
{
	for (auto it: m_platformArray)
	{
		std::cout << "x = " << it->getX() << " y = " << it->getY() << std::endl;
	}

}
