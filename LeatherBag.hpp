/*
**	LeatherBag.hpp 
**
*/

#ifndef LEATHERBAG_HPP
# define LEATHERBAG_HPP
# include "Player.hpp"

class		LeatherBag : public Player
{
public:
	LeatherBag();
	LeatherBag(Player::Slot slot);
	~LeatherBag();

	bool		isHuman();

private:

};

#endif	/*	LEATHERBAG_HPP	*/
