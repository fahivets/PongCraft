/*
**
**
*/

#pragma once
#include <memory>
#include "Block.hpp"

class BlockFactory
{
public:
	static std::shared_ptr<Block> createBlock(Block::Type type)
	{
		return (std::make_shared<Block>(type));
	}
};

