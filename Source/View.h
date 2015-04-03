#pragma once

#include "InputDevice.h"
#include "Definitions.h"

#ifdef _WIN32
#include "SDL.h"
#else
#include <SDL.h>
#endif

class View {
protected:
	GAME_FLT x;
	GAME_FLT y;
	GAME_VEC position;
	SDL_Renderer* renderer;
	InputDevice* iDevice;

public:
	View();
	~View();
	bool Initialize(SDL_Renderer* render, InputDevice* input, GAME_FLT x, GAME_FLT y);
	void Update(GAME_FLT gameTime);
	GAME_VEC getPosition();
};
