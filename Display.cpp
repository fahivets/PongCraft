/*
** Display.cpp
*/

#include "Display.hpp"
#include "Globals.hpp"
#include <iostream>

Display::Display() : m_w(Globals::WIN_W), m_h(Globals::WIN_H)
{}

Display::~Display()
{
	SDL_DestroyRenderer(m_ren);
	SDL_DestroyWindow(m_win);
//	m_win = nullptr;
//	m_ren = nullptr;
	//TTF_CloseFont(m_name_font);
	SDL_Quit();
}

bool	Display::createRenderer()
{
	m_ren = SDL_CreateRenderer(m_win, -1, SDL_RENDERER_ACCELERATED);
	
	if (m_ren == nullptr)
	{	
		std::cout << "[SDL_ERROR] "	<< SDL_GetError() << std::endl;
		SDL_DestroyWindow(m_win);
		SDL_Quit();
		return (false);
	}
	else
	{
		SDL_RenderSetLogicalSize(m_ren, m_w, m_h);
		SDL_SetRenderDrawColor(m_ren, 0, 0, 0, 255);	
		SDL_RenderClear(m_ren);
		return (true);
	}
}

bool	Display::createWindow()
{
	m_win = SDL_CreateWindow("PongCraft",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			m_w, m_h, 0);

	if (m_win == nullptr)
	{
		std::cerr << "[SDL_ERROR] " << SDL_GetError() << std::endl;
		SDL_Quit();
		return (false);
	}
	else
		return (true);
}

bool	Display::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		if (createWindow() && createRenderer())
			std::cout << "START_LOOP" << std::endl;
			return (true);
	}
	else
	{
		std::cerr << "[SDL_ERROR] " << SDL_GetError() << std::endl;
		return (false);
	}
}

