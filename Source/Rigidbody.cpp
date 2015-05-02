#include "GameFunctions.h"
#include "Rigidbody.h"

Rigidbody::Rigidbody() : Component() {
    ;
}

Rigidbody::~Rigidbody() {
    world_->DestroyBody(body);
}

void Rigidbody::Initialize(b2World* world) {
    this.world_ = world;
    // Gotta work on this
    bdef.type = b2_dynamicBody;
	bdef.position.Set(RW2PW(position.x), RW2PW(position.y));
	bdef.angle = RW2PWAngle(angle);
	bdef.bullet = true;
	bdef.angularDamping = 0.1;
	bdef.linearDamping = 0.1;
	bdef.linearVelocity = velocity;
	body_ = world_->CreateBody(&bdef);

	texture->GetDimensions(&w, &h);
	shape.m_radius = RW2PW(w/1.5f);
	shapefd.shape = &shape;
	shapefd.density = 10.0f;
	shapefd.friction = 0.0f;
	shapefd.restitution = 1.1f;
	body_->CreateFixture(&shapefd);
}

void RigidBody::Update(float32 delta_time) {
    if(physics_movable) {
        ExportPosition();
        ExportAngle();
    } else {
        ImportPosition();
        ImportAngle();
    }
}

void RigidBody::ExportPosition() {
    b2vec2 physPos = body_->GetPosition();
    Vector2 position;
    position.x = PW2RW(physPos.x);
    position.y = PW2RW(physPos.y);
    owner_->SetPosition(position);
}

void RigidBody::ExportAngle() {
    owner_->SetPosition(PW2RWAngle(body_->GetAngle()));
}

void RigidBody::ImportPosition() {
    ;
}

void RigidBody::ImportAngle() {
    ;
}
