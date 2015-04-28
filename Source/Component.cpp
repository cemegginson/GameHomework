#include "Component.h"

Component::Component(std::shared_ptr<GameObject> _owner); {
    owner = _owner;
}

Component::~Component() {
    delete owner;
}

// Component::Update() {
//     ;
// }
