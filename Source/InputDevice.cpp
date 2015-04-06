#include <iostream>
#include "InputDevice.h"

InputDevice::InputDevice() { gEvent = GAME_NA; }

InputDevice::~InputDevice() {}

bool InputDevice::Initialize(SDL_Event* event) {
	translations[SDLK_UP] = GAME_UP;
	translations[SDLK_DOWN] = GAME_DOWN;
	translations[SDLK_LEFT] = GAME_LEFT;
	translations[SDLK_RIGHT] = GAME_RIGHT;
	translations[SDLK_w] = GAME_W;
	translations[SDLK_a] = GAME_A;
	translations[SDLK_s] = GAME_S;
	translations[SDLK_d] = GAME_D;
	translations[SDLK_SPACE] = GAME_SPACE;

	keystates[GAME_UP] = false;
	keystates[GAME_DOWN] = false;
	keystates[GAME_LEFT] = false;
	keystates[GAME_RIGHT] = false;
	keystates[GAME_W] = false;
	keystates[GAME_A] = false;
	keystates[GAME_S] = false;
	keystates[GAME_D] = false;
	keystates[GAME_SPACE] = false;

	return true;
}

void InputDevice::Update(SDL_Event* event) {

	if(event->type == SDL_KEYDOWN){
		keystates[translations[event->key.keysym.sym]] = true;
	} else if(event->type == SDL_KEYUP) {
		keystates[translations[event->key.keysym.sym]] = false;
	}
}

bool InputDevice::IsPressed(GAME_EVENT event) {
	return keystates.at(event);
}

GAME_EVENT InputDevice::GetEvent() {
	return this->gEvent;
}
