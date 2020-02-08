/*
**	Player.hpp
**
*/

#ifndef PLAYER_HPP
# define PLAYER_HPP
# include "Platform.hpp"
# include <memory>

class		Player
{
public:
	enum class	Slot
	{
		Invalid,
		Left,
		Right
	};

	Player();
	Player(Player::Slot slot);
	virtual ~Player();

	void		moveUp();
	void		moveDown();
	
	std::shared_ptr<Platform>			getPlatform() const;
//	virtual bool		isHuman() = 0;

private:
	std::shared_ptr<Platform>	m_platform;
};

#endif	/*	PLAYER_HPP	*/
