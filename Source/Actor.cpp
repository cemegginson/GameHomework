#include "Actor.h"

Actor::Actor() {
    ;
}

Actor::~Actor() {
    ;
}

void Actor::Initialize() {

    
    actor_events_[MOVE_UP] = false;
    actor_events_[MOVE_DOWN] = false;
    actor_events_[MOVE_LEFT] = false;
    actor_events_[MOVE_RIGHT] = false;
    actor_events_[TURN_LEFT] = false;
    actor_events_[TURN_RIGHT] = false;
}

void Actor::AddComponent(std::shared_ptr<Component> component) {
    components_.insert(component);
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
