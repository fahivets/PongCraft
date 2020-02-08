/*
**	Menu.hpp
**
*/

#ifndef MENU_HPP
# define MENU_HPP
# include <SDL_ttf.h>
# include <SDL2/SDL.h>
# include "IGameObjectVisitor.hpp"

class		Menu
{
public:
	Menu();
	~Menu();

	bool		inMenu();
	void		openMenu();
	
	void	accept(IGameObjectVisitor const &visitor);

private:
	bool		m_inMenu;
	TTF_Font	*m_menuFont;
};

#endif	/*	MENU_HPP	*/
