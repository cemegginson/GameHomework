#pragma once

#include <string>
#include "Definitions.h"
#include "View.h"

#include "SDL.h"

class Texture {
protected:
    SDL_Texture* texture;
public:
	Texture();
	~Texture();
    bool Initialize(SDL_Renderer* renderer, std::string image);
	void Draw(SDL_Renderer* renderer, View* view, GAME_VEC position,
	     GAME_FLT angle, SDL_Rect* clip = nullptr);
};
