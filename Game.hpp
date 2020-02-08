/*
**	Game.hpp
**	TODO check what need includet
*/

#ifndef GAME_HPP
# define GAME_HPP
# include "Display.hpp"

class		Game
{
public:
	Game();
	~Game();

	bool	running();
	void	draw();
	void	gameLoop();

private:
	bool	m_isRunning;
	Display	m_display;
};

#endif	/*	GAME_HPP	*/
