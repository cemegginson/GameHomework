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
    b2Vec2 new_position;
    float32 new_angle;

    if(physics_movable_) {
        new_position = ExportPosition();
    } else {
        new_position = ImportPosition();
    }
    if(physics_turnable_) {
        new_angle = ExportAngle();
    } else {
        new_angle = ImportAngle();
    }
    body_->SetTransform(new_position, new_angle);
}

b2Vec2 RigidCircle::ExportPosition() {
    b2Vec2 physics_position = body_->GetPosition();
    Vector2 render_position;
    render_position.x = PW2RW(physics_position.x);
    render_position.y = PW2RW(physics_position.y);
    owner_->SetPosition(render_position);
    return physics_position;
}

float32 RigidCircle::ExportAngle() {
    float32 physics_angle = body_->GetAngle();
    owner_->SetAngle(PW2RWAngle(physics_angle));
    return physics_angle;
}

b2Vec2 RigidCircle::ImportPosition() {
    Vector2 render_position = owner_->GetPosition();
    b2Vec2 physics_position;
    physics_position.x = RW2PW(render_position.x);
    physics_position.y = RW2PW(render_position.y);
    return physics_position;
}

float32 RigidCircle::ImportAngle() {
    return RW2PWAngle(owner_->GetAngle());
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
    b2Vec2 new_position;
    float32 new_angle;

    if(physics_movable_) {
        new_position = ExportPosition();
    } else {
        new_position = ImportPosition();
    }
    if(physics_turnable_) {
        new_angle = ExportAngle();
    } else {
        new_angle = ImportAngle();
    }
    body_->SetTransform(new_position, new_angle);
}

b2Vec2 RigidRectangle::ExportPosition() {
    b2Vec2 physics_position = body_->GetPosition();
    Vector2 render_position;
    render_position.x = PW2RW(physics_position.x);
    render_position.y = PW2RW(physics_position.y);
    owner_->SetPosition(render_position);
    return physics_position;
}

float32 RigidRectangle::ExportAngle() {
    float32 physics_angle = body_->GetAngle();
    owner_->SetAngle(PW2RWAngle(physics_angle));
    return physics_angle;
}

b2Vec2 RigidRectangle::ImportPosition() {
    Vector2 render_position = owner_->GetPosition();
    b2Vec2 physics_position;
    physics_position.x = RW2PW(render_position.x);
    physics_position.y = RW2PW(render_position.y);
    return physics_position;
}

float32 RigidRectangle::ImportAngle() {
    return RW2PWAngle(owner_->GetAngle());
}
