/*
** Game.hpp
**
*/

#pragma once

# include <SDL2/SDL.h>
//# include <SDL_ttf.h>
# include <SDL_image.h>
//# include <SDL_mixer.h>
#include <map>
#include <iostream>

class			Game
{
public:
	Game();
	~Game();

	void			init();
	void			update();
	void			render();
	void			handleEvents();
	void			quit();
	bool			running();

private:
	bool			m_isRunning;
	unsigned int	m_w;
	unsigned int	m_h;
	SDL_Window		*m_win;
	SDL_Renderer	*m_ren;
	std::map<std::string, SDL_Surface*>	m_texturesMap;


};
