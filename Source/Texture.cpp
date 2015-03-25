#include <iostream>
#include <SDL_image.h>
#include "Texture.h"
//#include "GameUtils.h"

Texture::Texture() { texture = nullptr; }

Texture::~Texture() { SDL_DestroyTexture(texture); }

bool Texture::Initialize(SDL_Renderer* renderer, std::string image) {
	SDL_Surface* surface = nullptr;
	surface = IMG_Load(image.c_str());
	if(surface == NULL) {
		std::cerr << "Surface failed: " << IMG_GetError() << std::endl;
		return false;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	if (texture == NULL) {
		//LogSDLError(std::cerr, "LoadTexture");
		std::cerr << "Texture failed: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

void Texture::Draw(SDL_Renderer* renderer, View* view, GAME_VEC position,
		   GAME_FLT angle, SDL_Rect* clip) {
	SDL_Rect dst;
	dst.x = position.x;
	dst.y = position.y;

	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);

	SDL_RenderCopyEx(renderer, texture, NULL, &dst, angle, NULL, SDL_FLIP_NONE);
}
