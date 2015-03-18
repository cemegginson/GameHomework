#pragma once

#include "Definitions.h"

#ifdef _WIN32
#include "SDL.h"
#else
#include <SDL.h>
#endif

class InputDevice {
protected:
	GAME_EVENT gEvent;

public:
	InputDevice();
	~InputDevice();
	bool Initialize(SDL_Event* event);
	void Update(SDL_Event* event);
	GAME_EVENT Translate(SDL_Event* event);
	GAME_EVENT GetEvent();
};
