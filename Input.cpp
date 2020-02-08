/*
** Input.cpp
*/

#include "Input.hpp"

void	Input::buttonPressed(SDL_Keycode key)
{
    m_keysPressedMap[key] = true;
}

void	Input::buttonReleased(SDL_Keycode key)
{
    m_keysPressedMap[key] = false;
}

bool	Input::isKey(SDL_Keycode key)
{
    return (m_keysPressedMap[key]);
}
