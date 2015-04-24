#include "Box2D/Box2D.h"
#include "Component.h"

class Rigidbody : public Component {
protected:

public:
    Rigidbody();
    ~Rigidbody();
    Update();
}
