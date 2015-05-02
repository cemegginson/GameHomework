#include "Component.h"

Component::Component(std::shared_ptr<GameComponent> owner); {
    owner_ = owner;
}

Component::~Component() {
    delete owner_;
}
