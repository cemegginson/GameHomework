#include "GraphicsDevice.h"
#include "GameUtils.h"
#include <iostream>

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
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        LogSDLError(std::cerr, "SDL_Init");
        return false;
    }

    window = SDL_CreateWindow(“Game Homework 1”, SDL_WINDOWS_UNDEFINED,
				  SDL_WINDOWS_UNDEFINED, Width,
				  Height, SDL_WINDOW_SHOWN);
    if(window == nullptr) {
        LogSDLError(std::cerr, "SDL_CreateWindow");
        return false;
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_SOFTWARE);
    if(renderer == nullptr) {
        LogSDLError(std::cerr, "SDL_CreateRenderer");
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
