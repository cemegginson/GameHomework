#pragma once

#include "Definitions.h"

#include "SDL.h"

class GraphicsDevice {
	protected:
	int width;
	int height;
	SDL_Window* window;
	SDL_Renderer* renderer;

	public:
	GraphicsDevice();
	GraphicsDevice(GAME_INT ScreenWidth, GAME_INT ScreenHeight);
	~GraphicsDevice();
	bool Initialize();
	int getWidth();
	int getHeight();
	SDL_Renderer* getRenderer();
};
