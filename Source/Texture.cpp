#include "Texture.h"
#include "SDL_image.h"
#include <iostream>

Texture::Texture() { texture = nullptr; }

Texture::~Texture() { SDL_DestroyTexture(texture); }

bool Texture::Initialize(SDL_Renderer* renderer, std::string image) {
	SDL_Surface* surface = nullptr;
	surface = IMG_Load(image.c_str());
	if (surface == nullptr) {
		// LogSDLError(std::cerr, "LoadSurface");
		std::cerr << "Something broke" << std::endl;
		return false;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	if (texture == nullptr) {
		// LogSDLError(std::cerr, "LoadTexture");
		std::cerr << "Something broke" << std::endl;
		return false;
	}
	return true;
}

void Texture::Draw(SDL_Renderer* renderer, View* view, GAME_VEC position,
		   GAME_FLT angle, SDL_Rect* clip) {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, 0, 0);
}
