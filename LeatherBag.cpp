/*
**	LeatherBag.cpp
*/

#include "LeatherBag.hpp"

LeatherBag::LeatherBag()
{}

LeatherBag::LeatherBag(PlayerSlot slot) : Player(slot)
{}

LeatherBag::~LeatherBag()
{}

bool		LeatherBag::isHuman()
{
	return (true);
}
