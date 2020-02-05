/*
** Game.cpp
*/

#include "Game.hpp"
#include "Display.hpp"
#include "Input.hpp"
#include <memory> // dell
#include <iostream>

Game::Game() : m_w(640), m_h(480)
{}

Game::~Game()
{}

void	Game::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << "[SDL_ERROR] " << SDL_GetError() << std::endl;
		m_isRunning = false;
	}

	m_win = SDL_CreateWindow("PongCraft",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			m_w, m_h, 0);

	if (m_win == nullptr)
	{
		std::cerr << "[SDL_ERROR] " << SDL_GetError() << std::endl;
		m_isRunning = false;
	}

	m_ren = SDL_CreateRenderer(m_win, -1, SDL_RENDERER_ACCELERATED);
	if (m_ren == nullptr)
	{	
		std::cout << "[SDL_ERROR] "	<< SDL_GetError() << std::endl;
		m_isRunning = false;
	}

	m_texturesMap.insert(std::pair<std::string, SDL_Surface*> ("WHITE", IMG_Load("Resources/block_white.png")));
	
	SDL_RenderSetLogicalSize(m_ren, m_w, m_h);
	SDL_SetRenderDrawColor(m_ren, 0, 0, 0, 255);	
	SDL_RenderClear(m_ren);
	m_isRunning = true;
}

void	Game::update()
{}

void	Game::render()
{
	SDL_RenderClear(m_ren);

	SDL_RenderPresent(m_ren);
}

void	Game::handleEvents()
{	
	SDL_Event	event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				m_isRunning = false;
		}
		if (event.type == SDL_QUIT)
			m_isRunning = false;
	}
}

void	Game::quit()
{
	SDL_DestroyRenderer(m_ren);
	SDL_DestroyWindow(m_win);
	m_win = nullptr;
	m_ren = nullptr;
	//TTF_CloseFont(m_name_font);
	SDL_Quit();
}

bool	Game::running()
{
	return (m_isRunning);
}
