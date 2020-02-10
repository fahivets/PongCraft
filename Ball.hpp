/*
** Ball.hpp
** TODO make Vector2D<float> ?
*/

#ifndef BALL_HPP
# define BALL_HPP
# include "GameObject.hpp"
# include <memory>

class			Ball : public GameObject
{
public:
	using Ptr = std::shared_ptr<Ball>;

	Ball();
	Ball(float x, float y);

	float	getDirX() const;
	float	getDirY() const;
	float	getVelocity() const;

	void	setPos(float x, float y);
	void	setDir(float dirX, float dirY);
	void	setDirX(float dirX);
	void	setDirY(float dirY);
	void	setVelocity(float vel);

	void	accept(IGameObjectVisitor const &visitor);
	void	move(float dt);
	void	reset();

private:
	float	m_dirX;
	float	m_dirY;
	float	m_velocity;
};

#endif	/*	BALL_HPP	*/
