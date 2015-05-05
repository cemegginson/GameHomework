#include <math.h>
#include "Carrier.h"
#include "GameFunctions.h"

Carrier::Carrier(std::shared_ptr<Actor> owner) : Component(owner) {}

Carrier::~Carrier() {}

void Carrier::Update(float32 delta_time) {
	// angle += rotation * delta_time;
	// if(angle > 360) {
	// 	angle -= 360;
	// } else if(angle < 0) {
	// 	angle += 360;
	// }
	// float rAngle = (angle * (PI / 180.0)) - PI;
	// b2Vec2 physPosition;
	// physPosition.x = RW2PW((float)((radius * cos(rAngle)) + center.x));
	// physPosition.y = RW2PW((float)((radius * sin(rAngle)) + center.y));
	//
	// body->SetTransform(physPosition, rAngle);
	//
	// position.x = PW2RW(physPosition.x);
	// position.y = PW2RW(physPosition.y);
}

void Carrier::Initialize() {
// 	gDevice = gDev;
// 	texture = tex;
// 	world = wor;
// 	position = pos;
// 	angle = ang;
// 	rotation = 60;
// 	texture->GetDimensions(&w, &h);
// 	center = position;
// 	radius = rand() % 100;
// 	center.x += radius;
//
// 	// Physics stuff
// 	bdef.type = b2_dynamicBody;
// 	bdef.position.Set(RW2PW((int)position.x), RW2PW((int)position.y));
// 	bdef.angle = RW2PWAngle(angle);
// 	bdef.angularDamping = 10.0;
// 	bdef.linearDamping = 10.0;
// 	body = world->CreateBody(&bdef);
//
// 	shape.SetAsBox(RW2PW(w/2), RW2PW(h/2));
// 	shapefd.shape = &shape;
// 	shapefd.density = 0.1f;
// 	shapefd.friction = 0.0f;
// 	shapefd.restitution = 0.0f;
// 	body->CreateFixture(&shapefd);
}
