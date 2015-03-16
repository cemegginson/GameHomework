#pragma once

#ifdef _WIN32
#include "SDL2.h"
#else
#include <SDL2.h>
#endif

class InputDevice {
      protected:
	GAME_EVENT gEvent;

      public:
	InputDevice();
	~InputDevice();
	bool Initialize(SDL_Event*);
	Void Update(SDL_Event*);
	GAME_EVENT Translate(SDL_Event*);
	GAME_EVENT GetEvent();
}
