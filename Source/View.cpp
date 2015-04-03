#include "View.h"

View::View() {}

View::~View() {}

bool View::Initialize(SDL_Renderer* render, InputDevice* input, GAME_FLT x, GAME_FLT y) {
	iDevice = input;
	position.x = x;
	position.y = y;
	return true;
}

void View::Update(GAME_FLT gameTime) {
	GAME_EVENT gEvent = iDevice->GetEvent();
	switch(gEvent){
		case GAME_UP:
			position.y += 3;
			break;
		case GAME_DOWN:
			position.y -= 3;
			break;
		case GAME_LEFT:
			position.x -= 3;
			break;
		case GAME_RIGHT:
			position.x += 3;
			break;
	}
}

GAME_VEC View::getPosition() {
	return position;
}
