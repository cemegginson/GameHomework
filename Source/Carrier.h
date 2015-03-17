#pragma once

#include "Object.h"

class Carrier : Object {
protected:

public:
    Carrier();
    ~Carrier();
    void Update(GAME_FLT gameTime);
    void Draw(GAME_FLT gameTime, View* view);
    void Initialize();
}
