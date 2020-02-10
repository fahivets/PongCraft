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
	LeatherBag() = default;
	LeatherBag(PlayerSlot slot);
	~LeatherBag() = default;

	void	moveUp();
	void	moveDown();
	bool	isHuman();
};

#endif	/*	LEATHERBAG_HPP	*/
