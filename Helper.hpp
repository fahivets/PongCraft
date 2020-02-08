#pragma once

#include <memory>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <functional>

using SDLTextureUPtr = std::unique_ptr<SDL_Texture, std::function<void(SDL_Texture*)>>;
