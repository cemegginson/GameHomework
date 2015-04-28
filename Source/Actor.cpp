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
   for(auto comp : components) {
       std::shared_ptr<T> target;
       if((target = std::dynamic_pointer_cast<T>(comp))) {
           return(target);
       }
   }
   //Return NULL;
   return(std::shared_ptr<T>());
}

void Actor::Update(float32 deltaTime) {
    for(auto iter = components.begin(); iter != objects.end(); ++iter) {
        (*iter)->Update(deltaTime);
    }
}
