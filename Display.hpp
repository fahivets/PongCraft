/*
**	Display.hpp
**	SDL class
*/

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include <SDL2/SDL.h>
//# include <SDL_ttf.h>
# include <SDL_image.h>
# include <SDL_mixer.h>
# include <memory>

class			Display
{
public:
	Display();
	~Display();
	
	bool			createWindow();
	bool			createRenderer();
//	bool			loadTextures();
	bool			init();
	
private:
	unsigned int	m_w;
	unsigned int	m_h;
	SDL_Window		*m_win;
	SDL_Renderer	*m_ren;
//	SDL_Surface		*m_textures;
};

#endif	/*	DISPLAY_HPP	*/
