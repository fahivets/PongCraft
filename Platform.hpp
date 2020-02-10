/*
**	Platform.hpp
**
*/

#ifndef PLATFORM_HPP
# define PLATFORM_HPP
# include "Globals.hpp"
# include "Block.hpp"
# include "GameObject.hpp"
# include "PlayerSlot.hpp"
# include <memory>
# include <array>

class				Platform : public GameObject
{
public:
	using BlockPtr = std::shared_ptr<Block>;

	Platform();
	Platform(float x, float y, PlayerSlot slot);

	~Platform() = default;

	std::shared_ptr<Block>	getBlock(unsigned int id) const;
	std::array<std::shared_ptr<Block>, Globals::PLATFORM_MAX_SIZE> getArray() const;
	
	void					setBlock(unsigned int id, Block::Type type);
	void					accept(IGameObjectVisitor const &visitor);
	
private:
	std::array<std::shared_ptr<Block>, Globals::PLATFORM_MAX_SIZE>	m_platformArray;

	void	createLeftPlayer(float x, float y);
	void	createRightPlayer(float x, float y);
};

#endif	/*	PLATFORM_HPP	*/
