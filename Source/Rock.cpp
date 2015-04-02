#include "Rock.h"

Rock::Rock() : Object() {}

Rock::~Rock() {}

void Rock::Update(GAME_FLT gameTime) {}

void Rock::Draw(GAME_FLT gameTime, View* view) {
	texture->Draw(gDevice->getRenderer(), view, position, angle, nullptr);
}

void Rock::Initialize(GraphicsDevice* gDev, Texture* tex, GAME_VEC pos, GAME_FLT ang) {
	gDevice = gDev;
	texture = tex;
	position = pos;
	angle = ang;
}
