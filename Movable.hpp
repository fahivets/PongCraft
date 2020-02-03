/*
**
**
*/

#pragma once

class		Movable
{
public:
	Movable();
	Movable(unsigned int x, unsigned int y);
	virtual ~Movable() = default;

	unsigned int	getX() const;
	unsigned int	getY() const;
	void			setX(unsigned int x);
	void			setY(unsigned int y);

private:
	unsigned int	m_x;
	unsigned int	m_y;
};
