#include <math.h>
#include "Player.h"

Player::Player() : Object() {
	iDevice = nullptr;
}

Player::~Player() {}

void Player::Update(GAME_FLT gameTime) {

	GAME_FLT theta = (angle-90)*(PI/180.0);
	// GAME_VEC dst;
	// dst.x = travel * cos(theta);
	// dst.y = travel * sin(theta);

	switch(iDevice->GetEvent()){
		case GAME_A:
			angle -= 2.0;
			break;
		case GAME_D:
			angle += 2.0;
			break;
		case GAME_W:
			position.x += travel * cos(theta);
			position.y += travel * sin(theta);
			break;
		case GAME_S:
			position.x -= travel * cos(theta);
			position.y -= travel * sin(theta);
			break;
		default:
			break;
	}
}

void Player::Draw(GAME_FLT gameTime, View* view) {
	texture->Draw(gDevice->getRenderer(), view, position, angle, nullptr);
}

void Player::Initialize(GraphicsDevice* gDev, Texture* tex, GAME_VEC pos, GAME_FLT ang) {
	gDevice = gDev;
	texture = tex;
	position = pos;
	angle = ang;
}

void Player::setInput(InputDevice* iDev) {
	iDevice = iDev;
}
