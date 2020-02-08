/*
**	Menu.cpp
*/

#include "Menu.hpp"
#include <iostream>

Menu::Menu() : m_inMenu(true)
{
	if (TTF_Init() < 0)
	{	
		std::cerr << "[SDL_ERROR] " << SDL_GetError() << std::endl;
	}
	m_menuFont = TTF_OpenFont("Resources/font.ttf", 20);
	if (m_menuFont == nullptr)
	{
		std::cerr << "[SDL_ERROR] "	<< SDL_GetError() << std::endl;
		TTF_CloseFont(m_menuFont);
	}
}

Menu::~Menu()
{
	TTF_CloseFont(m_menuFont);
}

bool	Menu::inMenu()
{
	return(m_inMenu);
}

void		Menu::openMenu()
{
	SDL_Color textColor = { 255, 255, 255, 255 };	



}


void	Menu::accept(IGameObjectVisitor const &visitor)
{
	visitor.visit(*this);
}
