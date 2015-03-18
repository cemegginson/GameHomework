#include "GraphicsDevice.h"
#include "GameUtils.h"
#include <iostream>

GraphicsDevice::GraphicsDevice() {
    window = nullptr;
    renderer = nullptr;
    width = 0;
    height = 0;
}

GraphicsDevice::GraphicsDevice(GAME_INT ScreenWidth, GAME_INT ScreenHeight) {
	window = nullptr;
    renderer = nullptr;
    width = ScreenWidth;
    height = ScreenHeight;
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

    window = SDL_CreateWindow("Game Homework 1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
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

int GraphicsDevice::getWidth() {
    return width;
}

int GraphicsDevice::getHeight() {
    return height;
}
