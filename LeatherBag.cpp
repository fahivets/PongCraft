/*
**	LeatherBag.cpp
*/

#include "LeatherBag.hpp"

LeatherBag::LeatherBag()
{}

LeatherBag::LeatherBag(Player::Slot slot) : Player(slot)
{}

LeatherBag::~LeatherBag()
{}

bool		LeatherBag::isHuman()
{
	return (true);
}
