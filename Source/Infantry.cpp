#include "Infantry.h"

Infantry::Infantry() : Object() {}

Infantry::~Infantry() {}

void Infantry::Update(GAME_FLT gameTime) {
	angle += .5;
	if(angle > 360) {
		angle -= 360;
	} else if(angle < 0) {
		angle += 360;
	}
}

void Infantry::Draw(GAME_FLT gameTime, View* view) {
	texture->Draw(gDevice->getRenderer(), view, position, angle, nullptr);
}

void Infantry::Initialize(GraphicsDevice* gDev, Texture* tex, GAME_VEC pos, GAME_FLT ang) {
	gDevice = gDev;
	texture = tex;
	position = pos;
	angle = ang;
}
