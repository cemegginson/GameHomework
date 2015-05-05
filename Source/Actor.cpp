#include "Actor.h"

Actor::Actor() {
    ;
}

Actor::~Actor() {
    ;
}

void Actor::Initialize(std::string name, Vector2 position, uint32 angle) {
    name_ = name;
    position_ = position;
    angle_ = angle;
    movement_.x = 0;
    movement_.y = 0;
}

void Actor::AddComponent(Component* component) {
    components_.push_back(component);
}

void Actor::Update(float32 delta_time) {
    for(auto iter = components_.begin(); iter != components_.end(); ++iter) {
        (*iter)->Update(delta_time);
    }
}

Vector2 Actor::GetPosition() {
    return position_;
}
void Actor::SetPosition(Vector2 new_position) {
    position_ = new_position;
}

float32 Actor::GetAngle() {
    return angle_;
}
void Actor::SetAngle(float32 new_angle) {
    angle_ = new_angle;
}

Vector2 Actor::CheckMovement() {
    return movement_;
}

void Actor::SetMovement(Vector2 movement) {
    movement_ = movement;
}
