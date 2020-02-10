/*
**	Display.hpp
**	SDL class
*/

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include <SDL2/SDL.h>
# include <memory>
# include "DrawVisitor.hpp"

class			Display
{
public:
	Display();
	~Display();

	const DrawVisitor& getDrawVisitor();

private:
	void			initSDL();
	void			createWindow();
	bool			createRenderer();
	
	SDL_Window		*m_win;
	DrawVisitor		m_drawVisitor;
	unsigned int	m_w;
	unsigned int	m_h;
};

#endif	/*	DISPLAY_HPP	*/
