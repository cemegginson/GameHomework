#include "Texture.h"

Texture::Texture() {
    tex = nullptr;
}

Texture::~Texture() {
}

bool Texture::Initialize() {
    //tex = loadTexture();
    return true;
}

void Texture::Draw(SDL_Renderer* renderer, View* view, GAME_VEC position,
     GAME_FLT angle, SDL_Rect* clip) {

}
