/*
**	Game.cpp
*/

#include <chrono>
#include "Game.hpp"
#include "Input.hpp"
#include "Platform.hpp"
#include "Ball.hpp"
#include "Block.hpp"
#include "LeatherBag.hpp"
#include "AIPlayer.hpp"
#include "PhysicsManager.hpp"

Game::Game() : m_isRunning(false)
{}

Game::~Game()
{}

bool	Game::running()
{
	return (m_isRunning);
}

void	Game::quit()
{
	m_isRunning = false;
}

void	Game::gameLoop()
{
	SDL_Event		event;
	Input			input;
	PhysicsManager	physicsManager;

	auto ball = std::make_shared<Ball>();
	auto p1 = std::make_shared<LeatherBag>(PlayerSlot::Left);
	auto p2 = std::make_shared<AIPlayer>(PlayerSlot::Right);
	float	dt = 0.0f;
	m_isRunning = true;
	
	while (running())
	{
		auto startTime = std::chrono::high_resolution_clock::now();

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				quit();
			else if (event.type == SDL_KEYDOWN)
				input.buttonPressed(event.key.keysym.sym);
			else if (event.type == SDL_KEYUP)
				input.buttonReleased(event.key.keysym.sym);
			if (input.isKey(SDLK_ESCAPE))
				quit();		
			if (input.isKey(SDLK_w))
			{
				if (p1->isHuman())
					p1->moveUp();
			}
			if (input.isKey(SDLK_s))
			{
				if (p1->isHuman())
					p1->moveDown();	
			}
			if (input.isKey(SDLK_UP))
			{
				if (p2->isHuman())
					p2->moveUp();
			}
			if (input.isKey(SDLK_DOWN))
			{
				if (p2->isHuman())
					p2->moveDown();
			}
		}
		ball->move(dt);
		if (!p2->isHuman())
			p2->iqTest(ball);

		/*	collision	*/
		physicsManager.ballCollision(ball, p1, p2);
		physicsManager.checkBallPlayerCollision(ball, p1);
		physicsManager.checkBallPlayerCollision(ball, p2);
	
		/*	draw	*/
		p1->getPlatform()->accept(m_display.getDrawVisitor());
		p2->getPlatform()->accept(m_display.getDrawVisitor());
		p1->accept(m_display.getDrawVisitor());
		p2->accept(m_display.getDrawVisitor());
		ball->accept(m_display.getDrawVisitor());
		m_display.getDrawVisitor().drawScreen();
	
		auto stopTime = std::chrono::high_resolution_clock::now();
		dt = std::chrono::duration<float, std::chrono::milliseconds::period>(stopTime - startTime).count();
	}	/*	end gameLoop()	*/
}
