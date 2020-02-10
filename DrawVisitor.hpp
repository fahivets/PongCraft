/*
**	DrawVisitor.hpp
**
*/

#ifndef DRAWVISITOR_HPP
# define DRAWVISITOR_HPP

# include "IGameObjectVisitor.hpp"
# include "Globals.hpp"
# include "Helper.hpp"
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <map>
# include <string>

class		DrawVisitor : public IGameObjectVisitor
{
public:
	enum TextureType
	{
		Invalid,
		White,
		Green,
		Brown,
		Red
	};

	void	visit(Platform const &platform) const;
	void	visit(Ball const &ball) const;
	void	visit(Block const &block) const;
	void	visit(Player const &player) const;

	bool	loadTextures();
	bool	createRenderer(SDL_Window *m_win);
	bool	loadFont();
	void	drawScreen() const;

private:
	std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>> 	m_renderer;	
	std::unique_ptr<TTF_Font, std::function<void(TTF_Font*)>>			m_scoreFont;	
	std::map<TextureType, SDLTextureUPtr>								m_textureMap;	
};

#endif	/*	DRAWVISITOR_HPP	*/
