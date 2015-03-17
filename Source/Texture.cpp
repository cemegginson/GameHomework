#include "Texture.h"

Texture::Texture() {
    tex = nullptr;
}

Texture::Texture() {
    tex = loadTexture();
}

Texture::~Texture() {
}

bool Texture::Draw(SDL_Renderer* renderer, View* view, GAME_VEC position,
     GAME_FLT angle, SDL_Rect* clip = NULL) {

}
