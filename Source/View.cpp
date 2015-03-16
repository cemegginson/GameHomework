#include "View.h"

View::View() {

}

View::~View() {
    delete iDevice;
}

View::bool Initialize(InputDevice* input, GAME_FLT x, GAME_FLT y) {
    iDevice = input;
    position.x = x;
    position.y = y;
}

View::void Update(GAME_FLT gameTime) {

}
