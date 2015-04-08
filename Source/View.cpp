#include "View.h"

View::View() {}

View::~View() {}

bool View::Initialize(InputDevice* input, GAME_FLT x, GAME_FLT y) {
	iDevice = input;
	position.x = x;
	position.y = y;
	return true;
}

void View::Update(GAME_FLT deltaTime) {
	GAME_INT velocity = 400;
	if(iDevice->IsPressed(GAME_UP)) {
		position.y += velocity * deltaTime;
	}
	if(iDevice->IsPressed(GAME_DOWN)) {
		position.y -= velocity * deltaTime;
	}
	if(iDevice->IsPressed(GAME_LEFT)) {
		position.x += velocity * deltaTime;
	}
	if(iDevice->IsPressed(GAME_RIGHT)) {
		position.x -= velocity * deltaTime;
	}
	return;
}

GAME_VEC View::getPosition() {
	return position;
}
