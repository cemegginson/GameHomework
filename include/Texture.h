#pragma once

#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "Definitions.h"
#include "View.h"

class Texture {
protected:
	SDL_Texture* texture;

public:
	Texture();
	~Texture();
	bool Initialize(SDL_Renderer* renderer, std::string imPath);
	void Render(SDL_Renderer* renderer, View* view, Vector2 position,
		  float32 angle, SDL_Rect* clip = nullptr);
	void GetDimensions(int*, int*);
};
