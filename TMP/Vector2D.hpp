/*
** Vector class
**
*/

#pragma once
#define PI 3.14
#include <cmath>

template <typename Type>
class		Vector2D
{
public:
	Type	x;
	Type	y;

	Vector2D() : x(0.0), y(0.0)
	{}
	
	Vector2D(Type x, Type y) : x(x), y(y)
	{}

	Vector2D(Vector2D const &src) : x(src.x), y(src.y)
	{}
	
	Vector2D	&operator=(Vector2D const &other)
	{
		if (this != &other)
		{
			x = other.x;
			y = other.y;
		}
		return (*this);
	}
	
	Vector2D	operator+(Vector2D &other)
	{
		return (Vector2D(x + other.x, y + other.y));
	}

	Vector2D	operator-(Vector2D &other)
	{
		return (Vector2D(x - other.x, y - other.y));
	}
	
	Vector2D	&operator+=(Vector2D &other)
	{
		x += other.x;
		y += other.y;
		return (*this);
	}

	Vector2D	&operator-=(Vector2D &other)
	{
		x -= other.x;
		y -= other.y;
		return (*this);
	}
	
	Vector2D	operator+(float val)
	{
		return (Vector2D(x + val, y + val));
	}

	Vector2D	operator-(float val)
	{
		return (Vector2D(x - val, y - val));
	}

	Vector2D	operator*(float val)
	{
		return (Vector2D(x * val, y * val));
	}

	Vector2D	operator/(float val)
	{
		return (Vector2D(x / val, y / val));
	}
	
	Vector2D	&operator+=(float val)
	{
		x += val;
		y += val;
		return (*this);
	}

	Vector2D	&operator-=(float val)
	{
		x -= val;
		y -= val;
		return (*this);
	}

	Vector2D	&operator*=(float val)
	{
		x *= val;
		y *= val;
		return (*this);
	}

	Vector2D	&operator/=(float val)
	{
		x /= val;
		y /= val;
		return (*this);
	}
	
	void set(Type x, Type y)
	{
		x = x;
		y = y;
	}
	
	void rotate(float deg)
	{
		float theta = deg / 180.0 * PI;
		float cos_theta = cos(theta);
		float sin_theta = sin(theta);
		float tx = x * cos_theta - y * sin_theta;
		float ty = x * sin_theta + y * cos_theta;
	
		x = tx;
		y = ty;
	}
	
	Vector2D	&normalize()
	{
		if (length() == 0)
			return (*this);
		*this *= (1.0 / length());
		return (*this);
	}
	
	float dist(Vector2D vec) const
	{
		Vector2D dist(vec.x - x, vec.y - y);
		return (dist.length());
	}

	float length() const
	{
		return std::sqrt(x * x + y * y);
	}

	float dot(Vector2D vec1, Vector2D vec2)
	{
		return (vec1.x * vec2.x + vec1.y * vec2.y);
	}

	float cross(Vector2D vec1, Vector2D vec2)
	{
		return ((vec1.x * vec2.y) - (vec1.y * vec2.x));
	}
	
};
