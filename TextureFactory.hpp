/*
** namespace TextureFactory.hpp
*/

#ifndef TEXTUREFACTORY_HPP
# define TEXTUREFACTORY_HPP

#include "Helper.hpp"

#include <string>
#include <SDL_image.h>
#include <functional>

namespace	TextureFactory
{

	SDLTextureUPtr loadTexture(SDL_Renderer *renderer, std::string path)
	{
		auto *rawPtr = IMG_LoadTexture(renderer, path.c_str());
		auto deleter = [](SDL_Texture *texture) {
			SDL_DestroyTexture(texture);
		};
		return (SDLTextureUPtr(rawPtr, deleter));
	}

}	/*	end namespace TextureFactory	*/

#endif	/*	TEXTUREFACTORY_HPP	*/
