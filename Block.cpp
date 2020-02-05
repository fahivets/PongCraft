/*
**	Block.cpp
**	TODO:  может нужно будет в факторы передавать позицию
*/

#include "Block.hpp"
#include "Globals.hpp"

Block::Block() : GameObject(0, 0), m_type(Block::Type::Invalid)
{}

Block::Block(Block::Type type) : GameObject(0, 0), m_type(type)
{}

Block::Block(float x, float y, Block::Type type) : GameObject(x, y), m_type(type)
{}

Block::Block(Block const &src) : m_type(src.m_type)
{}

Block	&Block::operator=(Block const &rhs)
{
	if (this != &rhs)
	{
		m_type = rhs.m_type;
	}
	return (*this);
}

Block::Type		Block::getType() const
{
	return (m_type);
}

void			Block::setType(Block::Type type)
{
	m_type = type;
}

unsigned int	Block::blockSize() const
{
	return (Globals::BLOCK_SIZE);
}

/* future stuffs
 *
unsigned int	Block::mass() const
{
	return (blockTypeToMass(m_type));
}

unsigned int Block::blockTypeToMass(Block::Type type)
{
	static const std::map<Block::Type, unsigned int> typeToMassMap
	{
		{ Block::Type::White, 10 },
		{ Block::Type::Green, 15 },
		{ Block::Type::Brown, 20 }
	};

	auto it = typeToMassMap.find(type);

	if (it != typeToMassMap.end())
	{
		return it->second();
	}

	assert(false && "lol kek cheburek");
	return Block::Type::Invalid;
}
*/
