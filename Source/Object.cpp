#include "Object.h"

Object::Object() {
	gDevice = nullptr;
	iDevice = nullptr;
	texture = nullptr;
	position.x = 0;
	position.y = 0;
	angle = 0;
}

Object::~Object() {}
