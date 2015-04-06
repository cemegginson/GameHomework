#include <math.h>
#include "Player.h"

Player::Player() : Object() {
	iDevice = nullptr;
}

Player::~Player() {}

void Player::Update(GAME_FLT gameTime) {

	GAME_FLT theta = (angle-90)*(PI/180.0);

	GAME_EVENT event = iDevice->GetEvent();

	switch(event){
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

	// Create bullet if spacebar pressed
	if(event == GAME_SPACE){
		GAME_VEC direction;
		direction.x = 0;
		direction.y = 0;

		Bullet* bullet = new Bullet();
		bullet->Initialize(gDevice, aLibrary->Search("Bullet"), position, direction);
		bullets.push_back(bullet);
	}

	// Update bullet positions
	if(!bullets.empty()) {
		for(auto iter = bullets.begin(); iter != bullets.end(); ++iter){
			(*iter)->Update(gameTime);
		}
	}
}

void Player::Draw(GAME_FLT gameTime, View* view) {
	texture->Draw(gDevice->getRenderer(), view, position, angle, nullptr);

	if(!bullets.empty()) {
		for(auto iter = bullets.begin(); iter != bullets.end(); ++iter){
				(*iter)->Draw(gameTime, view);
		}
	}
}

void Player::Initialize(GraphicsDevice* gDev, Texture* tex, ArtAssetLibrary* aLib, GAME_VEC pos, GAME_FLT ang) {
	gDevice = gDev;
	texture = tex;
	aLibrary = aLib;
	position = pos;
	angle = ang;
}

void Player::setInput(InputDevice* iDev) {
	iDevice = iDev;
}
