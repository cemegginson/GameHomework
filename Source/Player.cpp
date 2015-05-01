#include <math.h>
#include "GameFunctions.h"
#include "Player.h"

Player::Player() : Object() {
	iDevice = nullptr;
	radius = 27;
	travel = 200;
	rotation = 500.0;
}

Player::~Player() {
	world->DestroyBody(body);
}

void Player::Update(float32 deltaTime) {

	float32 theta = (angle-90)*(PI/180.0);
	float32 tcos = cos(theta);
	float32 tsin = sin(theta);
	GAME_EVENT event = iDevice->GetEvent();

	b2Vec2 physPosition;
	physPosition = body->GetPosition();
	float32 physAngle = body->GetAngle();

	if(iDevice->IsPressed(GAME_A)) {
		physAngle = RW2PWAngle((PW2RWAngle(body->GetAngle()) - rotation * deltaTime));
	}
	if(iDevice->IsPressed(GAME_D)) {
		physAngle = RW2PWAngle((PW2RWAngle(body->GetAngle()) + rotation * deltaTime));
	}
	if(iDevice->IsPressed(GAME_W)) {
		physPosition.x += RW2PW(travel * tcos) * deltaTime;
		physPosition.y += RW2PW(travel * tsin) * deltaTime;
		//position.x += travel * tcos;
		//position.y += travel * tsin;
	}
	if(iDevice->IsPressed(GAME_S)) {
		physPosition.x -= RW2PW(travel * tcos) * deltaTime;
		physPosition.y -= RW2PW(travel * tsin) * deltaTime;
	}

	body->SetTransform(physPosition, physAngle);

	angle = PW2RW(physAngle);
	position.x = PW2RW(physPosition.x);
	position.y = PW2RW(physPosition.y);

	lastfiretime += deltaTime;
	// Create bullet if spacebar pressed
	if(iDevice->IsPressed(GAME_SPACE) && lastfiretime > .075){
		lastfiretime = 0;
		Vector2 direction;
		direction.x = 2 * tcos;
		direction.y = 2 * tsin;

		Vector2 bulletpos;
		bulletpos.x = position.x + center.x + radius * tcos;
		bulletpos.y = position.y + center.y + radius * tsin;

		Bullet* bullet = new Bullet();
		bullet->Initialize(gDevice, aLibrary->Search("Bullet"), world, bulletpos, direction);
		bullets.push_front(bullet);
	}

	// Update bullet positions
	if(!bullets.empty()) {
		for(auto iter = bullets.begin(); iter != bullets.end(); ++iter){
			if((*iter)->GetLife() >= .75) {
				if(bullets.erase(iter) == bullets.end()) {
					break;
				}
				continue;
			}
			(*iter)->Update(deltaTime);
		}
	}
}

void Player::Render(float32 gameTime, View* view) {
	texture->Render(gDevice->GetRenderer(), view, position, angle, nullptr);

	if(!bullets.empty()) {
		for(auto iter = bullets.begin(); iter != bullets.end(); ++iter){
				(*iter)->Render(gameTime, view);
		}
	}
}

void Player::Initialize(GraphicsDevice* gDev, Texture* tex, ArtAssetLibrary* aLib, b2World* wor, Vector2 pos, float32 ang) {
	gDevice = gDev;
	texture = tex;
	aLibrary = aLib;
	world = wor;
	position = pos;
	angle = ang;
	int w, h;
	texture->GetDimensions(&w, &h);
	center.x = (w/2);
	center.y = (h/2);
	lastfiretime = 0;

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

void Player::setInput(InputDevice* iDev) {
	iDevice = iDev;
}
