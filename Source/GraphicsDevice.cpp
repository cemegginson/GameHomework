#include "GraphicsDevice.h"
#include <iostream>

#ifdef _WIN32
#include "SDL2.h"
#else
#include <SDL2.h>
#endif

GraphicsDevice::GraphicsDevice() {
    window = nullptr;
    renderer = nullptr;
    Width = 0;
    Height = 0;
}

GraphicsDevice::GraphicsDevice(int ScreenWidth, int ScreenHeight) {
	window = nullptr;
    renderer = nullptr;
    Width = ScreenWidth;
    Height = ScreenHeight;
}

GraphicsDevice::~GraphicsDevice() {
    delete renderer;
    delete window;
}

bool GraphicsDevice::Initialize() {
    window = SDL_CreateWindow(“Game Homework 1”, SDL_WINDOWS_UNDEFINED,
				  SDL_WINDOWS_UNDEFINED, Width,
				  Height, SDL_WINDOW_SHOWN);
    if(window == nullptr) {
        LogSDLError(std::cerr, "CreateWindow");
        return false;
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr) {
        LogSDLError(std::cerr, "CreateRenderer");
        return false;
    }

    return true;
}

int GraphicsDevice::Width() {
    return width;
}

int GraphicsDevice::Height() {
    return Height;
}
