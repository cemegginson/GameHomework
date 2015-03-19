#pragma once

#include "Definitions.h"

#ifdef _WIN32
#include "SDL.h"
#else
#include <SDL.h>
#endif

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
