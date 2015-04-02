#include "Player.h"

Player::Player() : Object() {}

Player::~Player() {}

void Player::Update(GAME_FLT gameTime) {}

void Player::Draw(GAME_FLT gameTime, View* view) {
	texture->Draw(gDevice->getRenderer(), view, position, angle, nullptr);
}

void Player::Initialize(GraphicsDevice* gDev, Texture* tex, GAME_VEC pos, GAME_FLT ang) {
	gDevice = gDev;
	texture = tex;
	position = pos;
	angle = ang;
}
