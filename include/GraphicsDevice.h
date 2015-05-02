#pragma once

#include <list>
#include <memory>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "Definitions.h"
#include "Sprite.h"

class Sprite;

class GraphicsDevice {
protected:
	int width_;
	int height_;
	SDL_Window* window_;
	SDL_Renderer* renderer_;
	std::list<std::shared_ptr<Sprite>> sprites_;

public:
	GraphicsDevice();
	GraphicsDevice(uint32, uint32);
	~GraphicsDevice();
	bool Initialize();
	int GetWidth();
	int GetHeight();
	SDL_Renderer* GetRenderer();
	bool AddSprite(std::shared_ptr<Sprite>);
	void Render();
};
