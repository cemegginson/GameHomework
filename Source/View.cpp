#include "View.h"

View::View() {}

View::~View() {}

bool View::Initialize(InputDevice* input, GAME_FLT x, GAME_FLT y) {
	iDevice = input;
	position.x = x;
	position.y = y;
	return true;
}

void View::Update(GAME_FLT gameTime) {
	switch(iDevice.GetEvent()){
		case GAME_UP:
			position.y += 3;
			break;
		case GAME_DOWN;
			position.y -= 3;
			break;
		case GAME_LEFT;
			position.x -= 3;
			break;
		case GAME_RIGHT;
			position.x += 3;
			break;
	}

	SDL_Rect rect;
	rect.x = position.x;
	rect.y = position.y;
	rect.w = 0;
	rect.h = 0;

	SDL_RenderSetViewport(renderer, rect);
}
