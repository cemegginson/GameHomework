#pragma once

#include <memory>
#include <string>

#include "Component.h"
#include "Texture.h"

class GraphicsDevice;

class Sprite : public Component, public std::enable_shared_from_this {
protected:
    Texture* texture_;
    GraphicsDevice* graphics_device_;

public:
    Sprite();
    ~Sprite();
    void Initialize(GraphicsDevice*, Texture*);
    void Update(float32);
    void Render();
};
