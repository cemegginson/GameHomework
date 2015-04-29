#pragma once

#include <list>
#include <memory>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "Definitions.h"
#include "Sprite.h"

class GraphicsDevice {
protected:
	int width;
	int height;
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::list<std::shared_ptr<Sprite>> sprites;

public:
	GraphicsDevice();
	GraphicsDevice(uint32 ScreenWidth, uint32 ScreenHeight);
	~GraphicsDevice();
	bool Initialize();
	int getWidth();
	int getHeight();
	SDL_Renderer* GetRenderer();
	bool AddSprite(std::shared_ptr<Sprite>);
};
