/*
** Block class
** blockTypeToMass -> future stuffs + did i need cr destrutor and operator=?
*/

#pragma once
#include "Movable.hpp"

class				Block : public Movable
{
public:
	enum class		Type
	{
		Invalid,
		White,
		Green,
		Brown
	};

	Block(Block::Type type);
	Block(unsigned int x, unsigned int y, Block::Type type);
	
	Block::Type		getType() const;
	void			setType(Block::Type type);
	unsigned int	blockSize() const;

//	unsigned int	mass() const;

private:
	Type			m_type;
	
//	unsigned int 	blockTypeToMass(Block::Type type);
};
