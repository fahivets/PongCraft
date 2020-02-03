/*
**
** TODO: make operator[] вместо get and set
*/

#pragma once

#include "Block.hpp"
#include "Movable.hpp"
#include <memory>
#include <array>


class				Platform : public Movable
{
public:
	Platform(unsigned int x, unsigned int y);
	std::shared_ptr<Block>	getBlock(unsigned int id) const;
	void					setBlock(unsigned int id, Block::Type type);

private:
	std::array<std::shared_ptr<Block>, 15>	m_array;
};
