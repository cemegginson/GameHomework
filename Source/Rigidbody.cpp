#include "GameFunctions.h"
#include "Rigidbody.h"

Rigidbody::Rigidbody() : Component() {
    ;
}

Rigidbody::~Rigidbody() {
    ;
}

void Rigidbody::Initialize(b2World* world) {

    // Gotta work on this
    bdef.type = b2_dynamicBody;
	bdef.position.Set(RW2PW(position.x), RW2PW(position.y));
	bdef.angle = RW2PWAngle(angle);
	bdef.bullet = true;
	bdef.angularDamping = 0.1;
	bdef.linearDamping = 0.1;
	bdef.linearVelocity = velocity;
	body = world->CreateBody(&bdef);

	texture->GetDimensions(&w, &h);
	shape.m_radius = RW2PW(w/1.5f);
	shapefd.shape = &shape;
	shapefd.density = 10.0f;
	shapefd.friction = 0.0f;
	shapefd.restitution = 1.1f;
	body->CreateFixture(&shapefd);
}

void RigidBody::Update(float32 deltaTime) {
    ;
}

void RigidBody::ExportPosition() {
    b2vec2 physPos = body->GetPosition();
    Vector2 position;
    position.x = PW2RW(physPos.x);
    position.y = PW2RW(physPos.y);
    owner->SetPosition(position);
}

void RigidBody::ExportAngle() {
    owner->SetPosition(PW2RWAngle(angle));
}
