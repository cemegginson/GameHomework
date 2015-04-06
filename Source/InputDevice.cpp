#include <iostream>
#include "InputDevice.h"

InputDevice::InputDevice() { gEvent = GAME_NA; }

InputDevice::~InputDevice() {}

bool InputDevice::Initialize(SDL_Event* event) {
	this->gEvent = Translate(event);
	return true;
}

void InputDevice::Update(SDL_Event* event) {
	if(event->type == SDL_KEYDOWN){
		this->gEvent = Translate(event);
	} else if(event->type == SDL_KEYUP) {
		this->gEvent = GAME_NA;
	}
}

GAME_EVENT InputDevice::Translate(SDL_Event* event) {
	GAME_EVENT keyEvent = GAME_NA;
	switch(event->key.keysym.sym) {
		case SDLK_UP:
			keyEvent = GAME_UP;
			break;
		case SDLK_DOWN:
			keyEvent = GAME_DOWN;
			break;
		case SDLK_LEFT:
			keyEvent = GAME_LEFT;
			break;
		case SDLK_RIGHT:
			keyEvent = GAME_RIGHT;
			break;
		case SDLK_w:
			keyEvent = GAME_W;
			break;
		case SDLK_a:
			keyEvent = GAME_A;
			break;
		case SDLK_s:
			keyEvent = GAME_S;
			break;
		case SDLK_d:
			keyEvent = GAME_D;
			break;
		case SDLK_SPACE:
			keyEvent = GAME_SPACE;
			break;
		case SDLK_t:
			int* foo;
			*foo = 1;
			break;
		default:
			keyEvent = GAME_NA;
			break;
	}
	return keyEvent;
}

GAME_EVENT InputDevice::GetEvent() {
	return this->gEvent;
}
