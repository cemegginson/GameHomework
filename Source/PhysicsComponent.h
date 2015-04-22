#include "Box2D/Box2D.h"
#include "Component.h"

class PhysicsComponent : Component {
protected:

public:
    PhysicsComponent();
    ~PhysicsComponent();
    Update();
}
