/*
**	Game.cpp
*/

#include "Game.hpp"
#include "Input.hpp"
#include "Menu.hpp"

#include "Platform.hpp"
#include "Ball.hpp"
#include "Block.hpp"

#include "LeatherBag.hpp"

#include <iostream>

Game::Game() : m_isRunning(false)
{}

Game::~Game()
{}

bool	Game::running()
{
	return (m_isRunning);
}

void	Game::draw()
{
}

void	Game::gameLoop()
{
	SDL_Event event;
	Input input;
	Menu	menu;

/*	test VISITOR	*/
//	GameLogic gamelogic;

	Platform	test1(0, 300);
	Ball		test2;
	Block		test3;
/*	end test visitor	*/
	auto p1 = std::make_shared<LeatherBag>(Player::Slot::Left);
//	Player p1(Player::Slot::Left);

	m_isRunning = true;

	while (running())
	{
/*		input.handleInput();
		auto currentInput = input.currentInput();
		if (std::find(currentInput.b, currentInput.e, [](InputEvent ev) {
			return ev == Quit;
		 }) != currentInput.e) {
			m_isRunning = false;
		}
		gameLogic.onInputRecieved();
*/
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
			if (input.isKey(SDLK_ESCAPE))
				m_isRunning = false;

			if (input.isKey(SDLK_SPACE))
			{
				p1->getPlatform()->accept(m_display.getDrawVisitor());
			//	test1.accept(display.getDrawVisitor());
			//	test1.accept(*drawVisitor);
			//	test2.accept(drawVisitor);
			//	test3.accept(drawVisitor);	
			}
			
			if (input.isKey(SDLK_UP))
			{
				p1->moveUp();
			}
			if (input.isKey(SDLK_DOWN))
			{
				p1->moveDown();
			}
		}

		p1->getPlatform()->accept(m_display.getDrawVisitor());
		draw();

	}	/*	end gameLoop()	*/
}
