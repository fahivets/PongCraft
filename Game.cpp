/*
**	Game.cpp
*/

#include "Game.hpp"

Game::Game() : m_isRunning(false)
{}

Game::~Game()
{}

void	Game::init()
{	
	Display	display;
	if (display.init())
	{
		m_isRunning = true;
		gameLoop();
	}
	else
		exit(1);
}

bool	Game::running()
{
	return (m_isRunning);
}

void	Game::gameLoop()
{
	SDL_Event event;
	Input input;

	while (running())
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				m_isRunning = false;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				input.buttonPressed(event.key.keysym.sym);
			}
			else if (event.type == SDL_KEYUP)
			{
				input.buttonReleased(event.key.keysym.sym);
			}
		}
		if (input.isKey(SDLK_ESCAPE))
			m_isRunning = false;
		

	}	/*	end gameLoop()	*/
}
