#include <math.h>
#include <memory>
#include "GameFunctions.h"
#include "Player.h"

Player::Player() : Object() {
	input_device_ = nullptr;
	radius_ = 27;
	travel_ = 200;
	rotation_ = 500.0;
}

Player::~Player() {
	world->DestroyBody(body);
}

void Player::Update(float32 delta_time) {

	float32 theta = (angle-90)*(PI/180.0);
	float32 tcos = cos(theta);
	float32 tsin = sin(theta);
	GameEvent event = input_device_->GetEvent();

	b2Vec2 physPosition;
	physPosition = body->GetPosition();
	float32 physAngle = body->GetAngle();

	if(input_device_->IsPressed(GAME_A)) {
		physAngle = RW2PWAngle((PW2RWAngle(body->GetAngle()) - rotation * delta_time));
	}
	if(input_device_->IsPressed(GAME_D)) {
		physAngle = RW2PWAngle((PW2RWAngle(body->GetAngle()) + rotation * delta_time));
	}
	if(input_device_->IsPressed(GAME_W)) {
		physPosition.x += RW2PW(travel * tcos) * delta_time;
		physPosition.y += RW2PW(travel * tsin) * delta_time;
		//position.x += travel * tcos;
		//position.y += travel * tsin;
	}
	if(input_device_->IsPressed(GAME_S)) {
		physPosition.x -= RW2PW(travel * tcos) * delta_time;
		physPosition.y -= RW2PW(travel * tsin) * delta_time;
	}

	body->SetTransform(physPosition, physAngle);

	angle_ = PW2RW(physAngle);
	position_.x = PW2RW(physPosition.x);
	position_.y = PW2RW(physPosition.y);

	last_fire_time_ += delta_time;
	// Create bullet if spacebar pressed
	if(input_device_->IsPressed(GAME_SPACE) && last_fire_time_ > .075){
		last_fire_time_ = 0;
		Vector2 direction;
		direction.x = 2 * tcos;
		direction.y = 2 * tsin;

		Vector2 bulletpos;
		bulletpos.x = position.x + center.x + radius * tcos;
		bulletpos.y = position.y + center.y + radius * tsin;

		std::shared_ptr<Bullet> bullet = new Bullet();
		bullet->Initialize(graphics_device_, art_library->Search("Bullet"), world, bulletpos, direction);
		bullets.push_front(bullet);
	}
}

void Player::Initialize(GraphicsDevice* graphics_device, Texture* texture, ArtAssetLibrary* art_library, Vector2 position, float32 angle) {
	graphics_device_ = graphics_device;
	texture_ = texture;
	art_library_ = art_library;
	position_ = position;
	angle_ = angle;
	int w, h;
	texture_->GetDimensions(&w, &h);
	center_.x = (w/2);
	center_.y = (h/2);
	last_fire_time_ = 0;

	bdef.type = b2_dynamicBody;
	bdef.position.Set(RW2PW(position.x + 5), RW2PW(position.y + 5));
	bdef.angle = RW2PWAngle(angle);
	bdef.angularDamping = 10.0;
	bdef.linearDamping = 10.0;
	body = world->CreateBody(&bdef);

	shape.m_radius = RW2PW(w/2.0f);
	shapefd.shape = &shape;
	shapefd.density = 0.1f;
	shapefd.friction = 0.0f;
	shapefd.restitution = 0.0f;
	body->CreateFixture(&shapefd);
}

void Player::setInput(InputDevice* input_device) {
	input_device_ = input_device;
}
