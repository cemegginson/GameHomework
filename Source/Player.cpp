#include <math.h>
#include <memory>
#include "GameFunctions.h"
#include "Player.h"

Player::Player(std::shared_ptr<Actor> owner) : Component(owner) {
	input_device_ = nullptr;
	radius_ = 27;
	travel_ = 200;
	rotation_ = 500.0;
	last_fire_time_ = 0;
}

Player::~Player() {
	;
}

void Player::Update(float32 delta_time) {
	// GameEvent event = input_device_->GetEvent();
	float32 angle = owner_->GetAngle();
	Vector2 new_position = owner_->GetPosition();

	float32 theta = RW2PWAngle(angle);
	float32 tcos = cos(theta);
	float32 tsin = sin(theta);

	if(input_device_->IsPressed(GAME_A)) {
		angle = owner_->GetAngle() - rotation_ * delta_time;
	}
	if(input_device_->IsPressed(GAME_D)) {
		angle = owner_->GetAngle() + rotation_ * delta_time;
	}
	if(input_device_->IsPressed(GAME_W)) {
		// physPosition.x += RW2PW(travel * tcos) * delta_time;
		// physPosition.y += RW2PW(travel * tsin) * delta_time;
		new_position.x += travel_ * tcos * delta_time;
		new_position.y += travel_ * tsin * delta_time;
	}
	if(input_device_->IsPressed(GAME_S)) {
		new_position.x -= travel_ * tcos * delta_time;
		new_position.y -= travel_ * tsin * delta_time;
	}

	owner_->SetAngle(angle);
	owner_->SetPosition(new_position);

	last_fire_time_ += delta_time;
	// Create bullet if spacebar pressed
	// if(input_device_->IsPressed(GAME_SPACE) && last_fire_time_ > .075){
	// 	last_fire_time_ = 0;
	// 	Vector2 direction;
	// 	direction.x = 2 * tcos;
	// 	direction.y = 2 * tsin;
	//
	// 	Vector2 bulletpos;
	// 	bulletpos.x = position.x + center.x + radius * tcos;
	// 	bulletpos.y = position.y + center.y + radius * tsin;
	//
	// 	std::shared_ptr<Bullet> bullet = new Bullet();
	// 	bullet->Initialize(graphics_device_, art_library->Search("Bullet"), world, bulletpos, direction);
	// 	bullets.push_front(bullet);
	// }
}

void Player::Initialize() {
	;
}

void Player::SetInput(InputDevice* input_device) {
	input_device_ = input_device;
}
