/*
** Ball.hpp
** TODO make Vector2d
*/

#ifndef BALL_HPP
# define BALL_HPP
# include "GameObject.hpp"

class			Ball : public GameObject
{
public:
	Ball();
	Ball(float x, float y);

	float	getDirX() const;
	float	getDirY() const;
	float	getVelocity() const;
	
	void	setDir(float dirX, float dirY);
	void	setDirX(float dirX);
	void	setDirY(float dirY);
	void	setVelocity(float vel);

private:
	float	m_dirX;
	float	m_dirY;
	float	m_velocity;
};

#endif	/*	BALL_HPP	*/
