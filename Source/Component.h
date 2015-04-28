#include <memory>

#include "Actor.h"

class Component {
protected:
    std::shared_ptr<Actor> owner;
public:
    Component(std::shared_ptr<Actor>);
    ~Component();
    virtual void Update() = 0;
};
