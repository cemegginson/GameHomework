#pragma once

#include <map>
#include "Definitions.h"

#ifdef _WIN32
#include "SDL.h"
#else
#include <SDL.h>
#endif

class InputDevice {
protected:
	GAME_EVENT gEvent;
	std::map<SDL_Keycode, GAME_EVENT> translations;
	std::map<GAME_EVENT, bool> keystates;

public:
	InputDevice();
	~InputDevice();
	bool Initialize(SDL_Event* event);
	void Update(SDL_Event* event);
	bool IsPressed(GAME_EVENT event);
	GAME_EVENT GetEvent();
};
