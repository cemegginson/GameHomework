#pragma once

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
