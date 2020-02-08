/*
**	Display.hpp
**	SDL class TODO: smart_ptr on SDL?
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
	unsigned int	m_w; //del?
	unsigned int	m_h; // del?
};

#endif	/*	DISPLAY_HPP	*/
