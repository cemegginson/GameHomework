#include <math.h>
#include "Carrier.h"
#include "GameFunctions.h"

Carrier::Carrier() : Object() {}

Carrier::~Carrier() {}

void Carrier::Update(float32 deltaTime) {
	angle += rotation * deltaTime;
	if(angle > 360) {
		angle -= 360;
	} else if(angle < 0) {
		angle += 360;
	}
	float rAngle = (angle * (PI / 180.0)) - PI;
	b2Vec2 physPosition;
	physPosition.x = RW2PW((float)((radius * cos(rAngle)) + center.x));
	physPosition.y = RW2PW((float)((radius * sin(rAngle)) + center.y));

	body->SetTransform(physPosition, rAngle);

	position.x = PW2RW(physPosition.x);
	position.y = PW2RW(physPosition.y);
}

void Carrier::Draw(float32 gameTime, View* view) {
	texture->Draw(gDevice->getRenderer(), view, position, angle, nullptr);
}

void Carrier::Initialize(GraphicsDevice* gDev, Texture* tex, b2World* wor, GAME_VEC pos, float32 ang) {
	gDevice = gDev;
	texture = tex;
	world = wor;
	position = pos;
	angle = ang;
	rotation = 60;
	texture->GetDimensions(&w, &h);
	center = position;
	radius = rand() % 100;
	center.x += radius;

	// Physics stuff
	bdef.type = b2_dynamicBody;
	bdef.position.Set(RW2PW((int)position.x), RW2PW((int)position.y));
	bdef.angle = RW2PWAngle(angle);
	bdef.angularDamping = 10.0;
	bdef.linearDamping = 10.0;
	body = world->CreateBody(&bdef);

	shape.SetAsBox(RW2PW(w/2), RW2PW(h/2));
	shapefd.shape = &shape;
	shapefd.density = 0.1f;
	shapefd.friction = 0.0f;
	shapefd.restitution = 0.0f;
	body->CreateFixture(&shapefd);
}
