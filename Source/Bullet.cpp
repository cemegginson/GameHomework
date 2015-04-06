#include "Bullet.h"

Bullet::Bullet() : Object() {}

Bullet::~Bullet() {}

void Bullet::Update(GAME_FLT gameTime) {
	position.x += velocity.x;
	position.y += velocity.y;
}

void Bullet::Draw(GAME_FLT gameTime, View* view) {
	texture->Draw(gDevice->getRenderer(), view, position, NULL, nullptr);
}

void Bullet::Initialize(GraphicsDevice* gDev, Texture* tex, GAME_VEC origin, GAME_VEC ivelocity) {
	gDevice = gDev;
	texture = tex;
	position = origin;
	velocity = ivelocity;
}
