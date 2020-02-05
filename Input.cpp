/*
** Input.cpp
*/

#include "Input.hpp"

Input::Input()
{}

Input::~Input()
{}

void	Input::buttonPressed(SDL_Keycode key)
{
    m_keysPressed[key] = true;
}

void	Input::buttonReleased(SDL_Keycode key)
{
    m_keysPressed[key] = false;
}

bool	Input::isKey(SDL_Keycode key)
{
    return (m_keysPressed[key]);
}
