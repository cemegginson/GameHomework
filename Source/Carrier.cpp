#include "Carrier.h"

Carrier::Carrier() : Object() {}

Carrier::~Carrier() {}

void Carrier::Update(GAME_FLT gameTime) { angle += gameTime; }

void Carrier::Draw(GAME_FLT gameTime, View* view) {
	texture->Draw(gDevice->getRenderer(), view, position, angle, nullptr);
}

void Carrier::Initialize(std::string tex, GAME_VEC pos, GAME_FLT ang) {
	texture = artlib.Search(tex);
	position = pos;
	angle = ang;
}
