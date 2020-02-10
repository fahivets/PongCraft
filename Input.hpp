/*
**	Input.hpp
**
*/

#ifndef INPUT_HPP
# define INPUT_HPP
# include <map>
# include <SDL2/SDL.h>

class		Input
{
public:
    bool	isKey(SDL_Keycode key);
    void	buttonPressed(SDL_Keycode key);
    void	buttonReleased(SDL_Keycode key);

private:
    std::map <SDL_Keycode, bool>	m_keysPressedMap;
};

#endif	/*	INPUT_HPP	*/
