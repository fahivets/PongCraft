/*
**	GameObjcet.hpp
**	Main abstract class 
*/

#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP

class		GameObject
{
public:
	GameObject();
	GameObject(float x, float y);
	GameObject(GameObject const &src);
	GameObject &operator=(GameObject const &rhs);
	virtual ~GameObject() = default;

	float	getX() const;
	float	getY() const;
	void	setX(float x);
	void	setY(float y);

private:
	float	m_x;
	float	m_y;
};

#endif /*	GAMEOBJECT_HPP	*/
