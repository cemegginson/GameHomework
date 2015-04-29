#include "Component.h"

Component::Component(std::shared_ptr<GameObject> owner); {
    this->owner = owner;
}

Component::~Component() {
    delete owner;
}

// Component::Update() {
//     ;
// }
