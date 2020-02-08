/*
**	Platform.hpp
**	TODO: make operator[] вместо get and set
*/

#ifndef PLATFORM_HPP
# define PLATFORM_HPP
# include "Globals.hpp"
# include "Block.hpp"
# include "GameObject.hpp"
# include <memory>
# include <array>

class				Platform : public GameObject
{
public:
	Platform();
	Platform(float x, float y);

	~Platform() = default;

	std::shared_ptr<Block>	getBlock(unsigned int id) const;
	std::array<std::shared_ptr<Block>, Globals::PLATFORM_MAX_SIZE> getArray() const;
	
	void					setBlockPos(std::shared_ptr<Block> block, float x, float y);
	void					setBlock(unsigned int id, Block::Type type);
	void					accept(IGameObjectVisitor const &visitor);
	
	void	print(); //dell after

private:
	std::array<std::shared_ptr<Block>, Globals::PLATFORM_MAX_SIZE>	m_platformArray;
};

#endif	/*	PLATFORM_HPP	*/
