#include <iostream>
#include <SDL_image.h>
#include "Texture.h"
//#include "GameUtils.h"

Texture::Texture() { texture = nullptr; }

Texture::~Texture() { SDL_DestroyTexture(texture); }

bool Texture::Initialize(SDL_Renderer* renderer, std::string imPath) {
	SDL_Surface* surface = nullptr;
	surface = IMG_Load(imPath.c_str());
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

void Texture::Render(SDL_Renderer* renderer, View* view, vector2 position,
		   float32 angle, SDL_Rect* clip) {

	vector2 camera = view->getPosition();

	SDL_Rect dst;
	dst.x = position.x + camera.x;
	dst.y = position.y + camera.y;

	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);

	SDL_RenderCopyEx(renderer, texture, NULL, &dst, angle, NULL, SDL_FLIP_NONE);
}

void Texture::GetDimensions(int* w, int* h) {
	SDL_QueryTexture(texture, NULL, NULL, w, h);
	return;
}
