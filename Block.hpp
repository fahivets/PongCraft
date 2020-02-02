/*
** Block class
** blockTypeToMass -> future stuffs + did i need cr destrutor and operator=?
*/

#pragma once


class				Block
{
public:
	enum class		Type
	{
		Invalid,
		White,
		Green,
		Brown
	};

public:
	Block(Block::Type type);
	Block(unsigned int x, unsigned int y, Block::Type type);
	
	unsigned int	getX() const;
	unsigned int	getY() const;
	Block::Type		getType() const;
	void			setX(unsigned int x);
	void			setY(unsigned int y);
	void			setType(Block::Type type);

//	unsigned int	mass() const;

private:
	unsigned int	m_x;
	unsigned int	m_y;
	Type			m_type;
	
//	unsigned int 	blockTypeToMass(Block::Type type);
};
