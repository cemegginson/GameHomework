#include "Bullet.h"

Bullet::Bullet() : Object() {}

Bullet::~Bullet() {}

void Bullet::Update(GAME_FLT gameTime) {}

void Bullet::Draw(GAME_FLT gameTime, View* view) {
	texture->Draw(gDevice->getRenderer(), view, position, angle, nullptr);
}

void Bullet::Initialize(GraphicsDevice* gDev, Texture* tex, GAME_VEC pos, GAME_FLT ang) {
	gDevice = gDev;
	texture = tex;
	position = pos;
	angle = ang;
}
