/*
** namespace BlockFactory.hpp
*/

#ifndef BLOCKFACTORY_HPP
# define BLOCKFACTORY_HPP
#include <memory>
#include "Block.hpp"

namespace	BlockFactory
{

	std::shared_ptr<Block>	createBlock(float x, float y, Block::Type type)
	{
		return (std::make_shared<Block>(x, y, type));
	}

	std::shared_ptr<Block>	createBlock(Block::Type type)
	{
		return (std::make_shared<Block>(type));
	}

}	/*	end namespace BlockFactory	*/

#endif	/*	BLOCKFACTORY_HPP	*/
