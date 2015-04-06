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

	if(iDevice->IsPressed(GAME_UP)) {
		position.y += 3;
	}
	if(iDevice->IsPressed(GAME_DOWN)) {
		position.y -= 3;
	}
	if(iDevice->IsPressed(GAME_LEFT)) {
		position.x += 3;
	}
	if(iDevice->IsPressed(GAME_RIGHT)) {
		position.x -= 3;
	}
	return;
}

GAME_VEC View::getPosition() {
	return position;
}
