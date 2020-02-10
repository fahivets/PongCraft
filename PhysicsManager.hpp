/*
**	PhysicsManager.hpp
**	TODO make check conts params?
*/

#ifndef PHYSICSMANAGER_HPP
# define PHYSICSMANAGER_HPP
# include "Ball.hpp"
# include "Player.hpp"
# include "Platform.hpp"
# include "Block.hpp"
# include <memory>
# include <cmath>

class		Ball;
class		Player;
class		Platform;

class		PhysicsManager
{
public:
	bool	checkBallPlayerCollision(Ball::Ptr &ball, std::shared_ptr<Player> const  &player);
	bool	PlayerCollision(Ball::Ptr &ball, std::shared_ptr<Player> const &player);
	bool	blockCollision(Ball::Ptr & ball, Platform::BlockPtr &block);
	
	void	ballCollision(Ball::Ptr &ball,
			std::shared_ptr<Player> const &p1, std::shared_ptr<Player> const &p2);
};

#endif	/*	PHYSICSMANAGER_HPP	*/
