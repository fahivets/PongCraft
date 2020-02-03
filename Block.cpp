/*
**
**
*/
#define BLOCK_SIZE 32 //TODO: think about that
#include "Block.hpp"

// может нужно будет в факторы передавать позицию
Block::Block(Block::Type type) : Movable(0, 0), m_type(type)
{}

Block::Block(unsigned int x, unsigned int y, Block::Type type) : Movable(x, y), m_type(type)
{}

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
	return (BLOCK_SIZE); // -> 32
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
