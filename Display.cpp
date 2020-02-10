/*
** Display.cpp
*/

#include "Display.hpp"
#include "Globals.hpp"
#include <iostream>
#include <assert.h>

Display::Display() : m_w(Globals::WIN_W), m_h(Globals::WIN_H)
{
	initSDL();	
	createWindow();

	if (createRenderer())
		if (!m_drawVisitor.loadTextures() || !m_drawVisitor.loadFont())
			assert(false && "opss!"); // TODO
}

Display::~Display()
{
	SDL_DestroyWindow(m_win);
	SDL_Quit();
}

void	Display::initSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		std::cerr << "[SDL_ERROR] " << SDL_GetError() << std::endl;
}

void	Display::createWindow()
{
	m_win = SDL_CreateWindow("PongCraft",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			m_w, m_h, 0);
	if (m_win == nullptr)
	{
		std::cerr << "[SDL_ERROR] " << SDL_GetError() << std::endl;
		SDL_Quit();
	}
}

bool	Display::createRenderer()
{
	return (m_drawVisitor.createRenderer(m_win));
}

const DrawVisitor&		Display::getDrawVisitor()
{
	return (m_drawVisitor);
}
