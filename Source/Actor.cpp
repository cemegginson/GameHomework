#include "Actor.h"

Actor::Actor() {
    ;
}

Actor::~Actor() {
    ;
}

Actor::Update() {
    for(auto iter = components.begin(); iter != objects.end(); ++iter) {
        iter->Update();
    }
}

// Actor::Render() {
//     ;
// }
