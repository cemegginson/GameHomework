#pragma once

#include "Object.h"
#include "InputDevice.h"
#include "Definitions.h"

class View : Object{
      protected:

      public:
	View();
	~View();
	bool Initialize(InputDevice* input, GAME_FLT x, GAME_FLT y);
	void Update(GAME_FLT gameTime);
}
