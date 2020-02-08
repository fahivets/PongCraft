/*
**	DrawVisitor.cpp
*/

#include "DrawVisitor.hpp"
#include "Platform.hpp"
#include "Block.hpp"
#include "TextureFactory.hpp"

#include <iostream> //DELLLLL

DrawVisitor::DrawVisitor()
{
}

DrawVisitor::~DrawVisitor()
{
	SDL_DestroyRenderer(m_renderer);
}

void		DrawVisitor::visit(Platform const &platform) const
{

	std::cout << "Visit and draw PLATFORM" << std::endl;

   	//clear screen, draw each element, then flip the buffer
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);


	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 0xFF);
	// Draw the net
	for (int y = 0; y < Globals::WIN_H; ++y)
	{
		if (y % 5)
		{
			SDL_RenderDrawPoint(m_renderer, Globals::WIN_W / 2, y);
		}
	}

 	for (auto block : platform.getArray())
	{
		if (block->getType() != Block::Type::Invalid)
		{
			SDL_Rect rect {0, 0, Globals::BLOCK_SIZE, Globals::BLOCK_SIZE };
			rect.x = block->getX();
			rect.y = block->getY();
			auto *rawTexturePtr = m_textureMap.at(TextureType::Brown).get(); 
			SDL_RenderCopy(m_renderer, rawTexturePtr, NULL, &rect); 
		}
	}
	SDL_RenderPresent(m_renderer);
}

void		DrawVisitor::visit(Ball const &ball) const
{
	std::cout << "Visit and draw BALL" << std::endl;
}

void		DrawVisitor::visit(Block const &block) const
{
	std::cout << "Visit and draw BLOCK" << std::endl;
}

void		DrawVisitor::visit(Menu const &menu) const
{
	std::cout << "Visit and draw MENU" << std::endl;

}

bool	DrawVisitor::loadTextures()
{
	auto whitePtr = TextureFactory::loadTexture(m_renderer, "Resources/block_white.png");
	auto greenPtr = TextureFactory::loadTexture(m_renderer, "Resources/block_green.png");
	auto brownPtr = TextureFactory::loadTexture(m_renderer, "Resources/block_brown.png");
	auto redPtr = TextureFactory::loadTexture(m_renderer, "Resources/block_red.png");

	if (!whitePtr || !greenPtr || !brownPtr || !redPtr)
		return (false);
	m_textureMap[TextureType::White] = std::move(whitePtr);
	m_textureMap[TextureType::Green] = std::move(greenPtr);
	m_textureMap[TextureType::Brown] = std::move(brownPtr);
	m_textureMap[TextureType::Red] = std::move(redPtr);
	return (true);
}

bool	DrawVisitor::createRenderer(SDL_Window	*windowPtr)
{
	m_renderer = SDL_CreateRenderer(windowPtr, -1, SDL_RENDERER_ACCELERATED);	
	if (!m_renderer)
	{	
		std::cerr << "[SDL_ERROR] "	<< SDL_GetError() << std::endl;
		return (false);
	}
	SDL_RenderSetLogicalSize(m_renderer, Globals::WIN_W, Globals::WIN_H);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);	
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
	return (true);
}
