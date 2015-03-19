#include "Infantry.h"

Infantry::Infantry() : Object() {

}

Infantry::~Infantry() {

}

void Infantry::Update(GAME_FLT gameTime) {
	angle += gameTime;
}

void Infantry::Draw(GAME_FLT gameTime, View* view) {
	texture->Draw(gDevice->getRenderer(), view, position, angle, nullptr);
}

void Infantry::Initialize(std::string tex, GAME_VEC pos, GAME_FLT ang) {
    texture = artlib.Search(tex);
    position = pos;
    angle = ang;
}
