#pragma once

#include <string>

#include "Component.h"
#include "Texture.h"

class GraphicsDevice;

class Sprite : public Component {
protected:
    Texture* texture;
    GraphicsDevice* gDevice;

public:
    Sprite();
    ~Sprite();
    void Initialize(GraphicsDevice*, std::string);
    void Update(float32);
    void Render();
};
