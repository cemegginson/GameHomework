#include "Component.h"
#include "Texture.h"

class Sprite : public Component {
protected:
    Texture* texture;

public:
    Sprite();
    ~Sprite();
}
