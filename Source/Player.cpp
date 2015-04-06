#include <math.h>
#include "Player.h"

Player::Player() : Object() {
	iDevice = nullptr;
}

Player::~Player() {}

void Player::Update(GAME_FLT gameTime) {

	GAME_FLT theta = (angle-90)*(PI/180.0);
	GAME_FLT tcos = cos(theta);
	GAME_FLT tsin = sin(theta);
	GAME_EVENT event = iDevice->GetEvent();



	if(iDevice->IsPressed(GAME_A)) {
		angle -= 2.0;
	}
	if(iDevice->IsPressed(GAME_D)) {
		angle += 2.0;
	}
	if(iDevice->IsPressed(GAME_W)) {
		position.x += travel * tcos;
		position.y += travel * tsin;
	}
	if(iDevice->IsPressed(GAME_S)) {
		position.x -= travel * tcos;
		position.y -= travel * tsin;
	}



	// Create bullet if spacebar pressed
	if(iDevice->IsPressed(GAME_SPACE)){
		GAME_VEC direction;
		direction.x = 2 * tcos;
		direction.y = 2 * tsin;

		GAME_VEC bulletpos;
		bulletpos.x = position.x + center.x + radius * tcos;
		bulletpos.y = position.y + center.y + radius * tsin;

		Bullet* bullet = new Bullet();
		bullet->Initialize(gDevice, aLibrary->Search("Bullet"), bulletpos, direction);
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
	int w, h;
	texture->GetDimensions(&w, &h);
	center.x = (w/2)-2;
	center.y = (h/2)-1;
}

void Player::setInput(InputDevice* iDev) {
	iDevice = iDev;
}
