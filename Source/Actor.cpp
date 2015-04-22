#include "Actor.h"

Actor::Actor() {
    ;
}

Actor::~Actor() {
    ;
}

Actor::Update(float32 deltaTime) {
    for(auto iter = components.begin(); iter != objects.end(); ++iter) {
        iter->Update(deltaTime);
    }
}

// Actor::Render() {
//     ;
// }
