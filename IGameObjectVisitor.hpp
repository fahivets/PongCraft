/*
**	IGameObjectVisitor.hpp
**
*/

#ifndef IGAMEOBJECTVISITOR_HPP
# define IGAMEOBJECTVISITOR_HPP

class	Block;
class	Platform;
class	Ball;
class	Menu;
class	Player;

class		IGameObjectVisitor
{
public:
	IGameObjectVisitor() = default;
	virtual ~IGameObjectVisitor() = default;

	virtual void	visit(Platform const &platform) const = 0;
	virtual void	visit(Ball const &ball) const = 0;
	virtual void	visit(Block const &block) const = 0;
	virtual void	visit(Menu const &menu) const = 0; //TODO dell
	virtual void	visit(Player const &player) const = 0;
};

#endif	/*	GAMEOBJECTVISITOR_HPP	*/
