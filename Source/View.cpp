#include "View.h"

View::View() {}

View::~View() {}

bool View::Initialize(InputDevice* input, float32 x, float32 y) {
	iDevice = input;
	position.x = x;
	position.y = y;
	return true;
}

void View::Update(float32 deltaTime) {
	uint32 velocity = 400;
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

vector2 View::getPosition() {
	return position;
}
