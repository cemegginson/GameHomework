#include <iostream>
#include "InputDevice.h"

InputDevice::InputDevice() { gEvent = GAME_NA; }

InputDevice::~InputDevice() {}

bool InputDevice::Initialize(SDL_Event* event) {
	gEvent = Translate(event);
	return true;
}

void InputDevice::Update(SDL_Event* event) {
	switch(event->type){
		case SDL_KEYDOWN:
			gEvent = Translate(event);
			break;
		default:
			break;
	}
}

GAME_EVENT InputDevice::Translate(SDL_Event* event) {
	switch(event->key.keysym.sym) {
		case SDLK_UP:
			gEvent = GAME_UP;
			break;
		case SDLK_DOWN:
			gEvent = GAME_DOWN;
			break;
		case SDLK_LEFT:
			gEvent = GAME_LEFT;
			break;
		case SDLK_RIGHT:
			gEvent = GAME_RIGHT;
			break;
		case SDLK_w:
			gEvent = GAME_W;
			break;
		case SDLK_a:
			gEvent = GAME_A;
			break;
		case SDLK_s:
			gEvent = GAME_S;
			break;
		case SDLK_d:
			gEvent = GAME_D;
			break;
		default:
			gEvent = GAME_NA;
			break;
	}
	return gEvent;
}

GAME_EVENT InputDevice::GetEvent() {
	return gEvent;
}
