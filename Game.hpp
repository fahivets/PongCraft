/*
**	Game.hpp
**
*/

#ifndef GAME_HPP
# define GAME_HPP
# include "Display.hpp"
# include "Input.hpp"

class		Game
{
public:
	Game();
	~Game();

	void	init();
	bool	running();
	void	gameLoop();

private:
	bool	m_isRunning;

};

#endif	/*	GAME_HPP	*/
