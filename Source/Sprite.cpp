#include "Sprite.h"

Sprite::Sprite() {
    texture = nullptr;
}

Sprite::~Sprite() {
    delete texture;
}
