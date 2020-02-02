/*
**
**
*/

#include "Block.hpp"

Block::Block(Block::Type type) : m_x(0), m_y(0), m_type(type)
{}

Block::Block(unsigned int x, unsigned int y, Block::Type type) : m_x(x), m_y(y), m_type(type)
{}

unsigned int	Block::getX() const
{
	return (m_x);
}

unsigned int	Block::getY() const
{
	return (m_y);
}

Block::Type		Block::getType() const
{
	return (m_type);
}

void			Block::setX(unsigned int x)
{
	m_x = x;
}

void			Block::setY(unsigned int y)
{
	m_y = y;
}

void			Block::setType(Block::Type type)
{
	m_type = type;
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
