#pragma once

#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "Definitions.h"
#include "View.h"

class Texture {
protected:
	SDL_Texture* texture_;

public:
	Texture();
	~Texture();
	bool Initialize(SDL_Renderer*, std::string);
	void Render(SDL_Renderer*, View*, Vector2, float32, SDL_Rect* clip);
	void GetDimensions(int*, int*);
};
