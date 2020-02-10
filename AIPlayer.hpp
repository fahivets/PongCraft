/*
**	AIPlayer.hpp
**
*/

#ifndef AIPLAYER_HPP
# define AIPLAYER_HPP
#include "Player.hpp"
#include "Ball.hpp"

class		AIPlayer : public Player
{
public:
	AIPlayer() = default;
	AIPlayer(PlayerSlot slot);
	~AIPlayer() = default;

	void	moveUp();
	void	moveDown();
	bool	isHuman();
	void	iqTest(Ball::Ptr const &ball);
private:
	float	m_step;
};

#endif	/*	AIPLAYER-HPP	*/
