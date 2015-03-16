#pragma once

#include "Definitions.h"

#ifdef _WIN32
#include "SDL2.h"
#else
#include <SDL2.h>
#endif

class Texture{
      protected:
    SDL_Texture* tex;
      public:
	Texture();
	~Texture();
	Draw(SDL_Renderer* renderer, View* view, GAME_VEC position,
	     GAME_FLT angle, SDL_Rect* clip = NULL);
}
