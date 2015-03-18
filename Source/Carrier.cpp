#include "Carrier.h"
#include "ArtAssetLibrary.h"

Carrier::Carrier() : Object() {

}

Carrier::~Carrier() {

}

void Carrier::Update(GAME_FLT gameTime) {

}

void Carrier::Draw(GAME_FLT gameTime, View* view) {

}

void Carrier::Initialize(std::string tex, GAME_VEC pos, GAME_FLT ang) {
    texture = ArtAssetLibrary::Search(tex);
    position = pos;
    angle = ang;
}
