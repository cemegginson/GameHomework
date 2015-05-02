#include "Actor.h"

Actor::Actor() {
    ;
}

Actor::~Actor() {
    ;
}

void Actor::AddComponent(std::shared_ptr<Component>) {
    ;
}

std::shared_ptr<T> Actor::GetComponent() {
   for(auto comp : components_) {
       std::shared_ptr<T> target;
       if((target = std::dynamic_pointer_cast<T>(comp))) {
           return(target);
       }
   }
   //Return NULL;
   return(std::shared_ptr<T>());
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
