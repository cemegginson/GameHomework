#include "Component.h"

Component::Component(std::shared_ptr<GameObject> owner); {
    owner_ = owner;
}

Component::~Component() {
    delete owner_;
}
