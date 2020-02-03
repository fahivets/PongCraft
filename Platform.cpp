/*
** Platform.cpp
** TODO: protect id, cr blcok XY in constructor.
*/

#include "Platform.hpp"
#include "BlockFactory.hpp"

Platform::Platform(unsigned int x, unsigned int y) : Movable(x, y)
{
	m_array[1] = BlockFactory::createBlock(getX(), getY(), Block::Type::White);
	m_array[2] = BlockFactory::createBlock(getX(), getY(), Block::Type::White);
	m_array[3] = BlockFactory::createBlock(getX(), getY(), Block::Type::White);
}


std::shared_ptr<Block>	Platform::getBlock(unsigned int id) const
{
	return (m_array[id]);
}


void					Platform::setBlock(unsigned int id, Block::Type type)
{
	m_array[id] = BlockFactory::createBlock(getX(), getY(), type);
}

