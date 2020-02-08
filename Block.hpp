/*
**	Block class
**	blockTypeToMass -> future stuffs
**	TODO: did i need cr destrutor and operator=?
*/

#ifndef BLOCK_HPP
# define BLOCK_HPP
#include "GameObject.hpp"

class				Block : public GameObject
{
public:
	enum class		Type
	{
		Invalid,
		White,
		Green,
		Brown
	};

	Block();
	Block(Block::Type type);
	Block(float x, float y, Block::Type type);
	Block(Block const &src);
	Block	&operator=(Block const &rhs);
	~Block() = default;

	Block::Type		getType() const;
	void			setType(Block::Type type);
	unsigned int	blockSize() const;
	void			accept(IGameObjectVisitor const &visitor);

//	unsigned int	mass() const;

private:
	Type			m_type;
	
//	unsigned int 	blockTypeToMass(Block::Type type);
};

#endif	/*	BLOCK_HPP	*/
