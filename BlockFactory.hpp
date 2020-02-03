/*
** BlockFactory.hpp
*/

#pragma once
#include <memory>
#include "Block.hpp"

namespace					BlockFactory
{

	std::shared_ptr<Block>	createBlock(unsigned int x, unsigned int y, Block::Type type)
	{
		return (std::make_shared<Block>(x, y, type));
	}

	std::shared_ptr<Block>	createBlock(Block::Type type)
	{
		return (std::make_shared<Block>(type));
	}

} /* end namespace BlockFactory */
