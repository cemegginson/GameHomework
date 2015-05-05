#include "GameFunctions.h"
#include "Physics.h"

Rigidbody::Rigidbody() {
    ;
}

Rigidbody::~Rigidbody() {
    world_->DestroyBody(body_);
}


// RigidCircle methods

RigidCircle::RigidCircle(std::shared_ptr<Actor> owner) : Component(owner), Rigidbody() {
    ;
}

RigidCircle::~RigidCircle() {
    ;
}

void RigidCircle::Initialize(b2World* world, b2BodyDef body_definition, b2FixtureDef shape_fixture_definition, bool movable, bool turnable) {
    world_ = world;
    body_ = world->CreateBody(&body_definition);
    body_->CreateFixture(&shape_fixture_definition);
    physics_movable_ = movable;
    physics_turnable_ = turnable;
}

void RigidCircle::Update(float32 delta_time) {
    if(physics_movable_) {
        ExportPosition();
    } else {
        ImportPosition();
    }
    if(physics_turnable_) {
        ExportAngle();
    } else {
        ImportAngle();
    }
}

void RigidCircle::ExportPosition() {
    b2Vec2 physics_position = body_->GetPosition();
    Vector2 position;
    position.x = PW2RW(physics_position.x);
    position.y = PW2RW(physics_position.y);
    owner_->SetPosition(position);
}

void RigidCircle::ExportAngle() {
    owner_->SetAngle(PW2RWAngle(body_->GetAngle()));
}

void RigidCircle::ImportPosition() {
    ;
}

void RigidCircle::ImportAngle() {
    ;
}

// RigidRectangle methods

RigidRectangle::RigidRectangle(std::shared_ptr<Actor> owner) : Component(owner), Rigidbody() {
    ;
}

RigidRectangle::~RigidRectangle() {
    ;
}

void RigidRectangle::Initialize(b2World* world, b2BodyDef body_definition, b2FixtureDef shape_fixture_definition, bool movable, bool turnable) {
    world_ = world;
    body_ = world->CreateBody(&body_definition);
    body_->CreateFixture(&shape_fixture_definition);
    physics_movable_ = movable;
    physics_turnable_ = turnable;
}

void RigidRectangle::Update(float32 delta_time) {
    if(physics_movable_) {
        ExportPosition();
    } else {
        ImportPosition();
    }
    if(physics_turnable_) {
        ExportAngle();
    } else {
        ImportAngle();
    }
}

void RigidRectangle::ExportPosition() {
    b2Vec2 physics_position = body_->GetPosition();
    Vector2 position;
    position.x = PW2RW(physics_position.x);
    position.y = PW2RW(physics_position.y);
    owner_->SetPosition(position);
}

void RigidRectangle::ExportAngle() {
    owner_->SetAngle(PW2RWAngle(body_->GetAngle()));
}

void RigidRectangle::ImportPosition() {
    ;
}

void RigidRectangle::ImportAngle() {
    ;
}
