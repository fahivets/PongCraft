/*
**	DrawVisitor.cpp
*/

#include "DrawVisitor.hpp"
#include "Platform.hpp"
#include "Block.hpp"
#include "TextureFactory.hpp"
#include "Ball.hpp"
#include "Player.hpp"
#include <string>
#include <iostream>

DrawVisitor::DrawVisitor()
{}

DrawVisitor::~DrawVisitor()
{}

void		DrawVisitor::visit(Platform const &platform) const
{
 	for (auto block : platform.getArray())
	{
		if (block->getType() != Block::Type::Invalid)
		{
			SDL_Rect rect {
				static_cast<int>(block->getX()),
				static_cast<int>(block->getY()),
				Globals::BLOCK_SIZE,
				Globals::BLOCK_SIZE
			};
			auto *rawTexturePtr = m_textureMap.at(TextureType::White).get(); 
			SDL_RenderCopy(m_renderer.get(), rawTexturePtr, NULL, &rect); 
		}
	}
}

void		DrawVisitor::visit(Ball const &ball) const
{	
	SDL_Rect rect {
		static_cast<int>(ball.getX() - Globals::BALL_SIZE / 2),
		static_cast<int>(ball.getY() - Globals::BALL_SIZE / 2),
		Globals::BALL_SIZE,
		Globals::BALL_SIZE
	};

	auto *rawTexturePtr = m_textureMap.at(TextureType::Red).get(); 
	SDL_RenderCopy(m_renderer.get(), rawTexturePtr, NULL, &rect); 

}

void		DrawVisitor::visit(Block const &block) const
{
	std::cout << "Visit and draw BLOCK" << std::endl;
}

void		DrawVisitor::visit(Menu const &menu) const
{
	std::cout << "Visit and draw MENU" << std::endl;

}

void	DrawVisitor::visit(Player const &player) const
{
	int 			textWidth;
	int				textHeight;
	std::string		currScore = std::to_string(player.getScore());

	SDL_Color textColor = { 255, 255, 255, 255 };
	SDL_Surface* textSurface = TTF_RenderText_Blended(m_scoreFont.get(), currScore.c_str(), textColor);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer.get(), textSurface);
	textWidth = textSurface->w;
	textHeight = textSurface->h;
	
	SDL_Rect rect = { 0, 20, textWidth, textHeight };
	if (player.getSlot() == PlayerSlot::Left)
		rect.x = Globals::WIN_CENTER_X / 2 - textWidth / 2;
	else
		rect.x = Globals::WIN_CENTER_X + Globals::WIN_CENTER_X / 2;

	SDL_RenderCopy(m_renderer.get(), texture, nullptr, &rect);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(texture);
}

bool	DrawVisitor::loadTextures()
{
	auto whitePtr = TextureFactory::loadTexture(m_renderer.get(),
			"Resources/block_white.png");
	auto greenPtr = TextureFactory::loadTexture(m_renderer.get(),
			"Resources/block_green.png");
	auto brownPtr = TextureFactory::loadTexture(m_renderer.get(),
			"Resources/block_brown.png");
	auto redPtr = TextureFactory::loadTexture(m_renderer.get(),
			"Resources/block_red.png");

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
	m_renderer = std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>>
		(SDL_CreateRenderer(windowPtr, -1, SDL_RENDERER_ACCELERATED),
		[](SDL_Renderer *renderer) { SDL_DestroyRenderer(renderer);	});
	
	if (!m_renderer)
	{	
		std::cerr << "[SDL_ERROR] "	<< SDL_GetError() << std::endl;
		return (false);
	}
	SDL_RenderSetLogicalSize(m_renderer.get(), Globals::WIN_W, Globals::WIN_H);
	SDL_RenderClear(m_renderer.get());
	SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);	
	SDL_RenderPresent(m_renderer.get());
	return (true);
}

bool	DrawVisitor::loadFont()
{
	if (TTF_Init() < 0)
	{	
		std::cerr << "[SDL_ERROR] " << SDL_GetError() << std::endl;
		return (false);
	}
	m_scoreFont = std::unique_ptr<TTF_Font, std::function<void(TTF_Font*)>>
		(TTF_OpenFont("Resources/font.ttf", 40),
		[](TTF_Font *font) { TTF_CloseFont(font); });
	if (m_scoreFont == nullptr)
	{
		std::cerr << "[SDL_ERROR] "	<< SDL_GetError() << std::endl;
		return (false);
	}
	return (true);
}

void	DrawVisitor::drawScreen() const
{
	SDL_SetRenderDrawColor(m_renderer.get(), 255, 255, 255, 0xFF);
	for (int y = 0; y < Globals::WIN_H; ++y)
	{
		if (y % 5)
		{
			SDL_RenderDrawPoint(m_renderer.get(), Globals::WIN_W / 2, y);
		}
	}
	SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);
	SDL_RenderPresent(m_renderer.get());
    SDL_RenderClear(m_renderer.get());
}
