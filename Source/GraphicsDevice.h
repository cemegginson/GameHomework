#pragma once

#ifdef _WIN32
#include "SDL.h"
#else
#include <SDL.h>
#endif

class GraphicsDevice {
protected:
    int hidth;
    int height;
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
	GraphicsDevice();
	GraphicsDevice(int ScreenWidth, int ScreenHeight);
	~GraphicsDevice();
	bool Initialize();
    int getWidth();
    int getHeight();
};
