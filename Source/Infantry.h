#pragma once

#include "Object.h"

class Infantry : Object {
protected:

public:
    Infantry();
    ~Infantry();
    void Update(GAME_FLT gameTime);
    void Draw(GAME_FLT gameTime, View* view);
    void Initialize();
}
