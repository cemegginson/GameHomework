#include "View.h"

View::View() {}

View::~View() {}

bool View::Initialize(InputDevice* input, GAME_FLT x, GAME_FLT y) {
	iDevice = input;
	position.x = x;
	position.y = y;
	return true;
}

void View::Update(GAME_FLT gameTime) {}
