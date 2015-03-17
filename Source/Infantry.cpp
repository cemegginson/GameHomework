#include "Infantry.h"

Infantry::Infantry() : Object() {

}

Infantry::~Infantry() {

}

void Infantry::Update(GAME_FLT gameTime) {

}

void Infantry::Draw(GAME_FLT gameTime, View* view) {

}

void Infantry::Initialize(GraphicsDevice* gdev, InputDevice* input, std::string tex, GAME_VEC pos, GAME_FLT ang) {
    gDevice = gdev;
    iDevice = input;
    texture = tex;
    position = pos;
    angle = ang;
}
