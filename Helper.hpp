/*
**	Helper.hpp
*/

#ifndef HELPER_HPP
# define HELPER_HPP

#include <memory>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <functional>

using SDLTextureUPtr = std::unique_ptr<SDL_Texture, std::function<void(SDL_Texture*)>>;

#endif	/*	HELPER_HPP	*/
