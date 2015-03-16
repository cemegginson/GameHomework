#pragma once

#include "Definitions.h"

#ifdef _WIN32
#include "SDL.h"
#else
#include <SDL.h>
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
