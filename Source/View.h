#pragma once

#include "InputDevice.h"
#include "Definitions.h"

class View {
protected:
	GAME_FLT x;
	GAME_FLT y;
	GAME_VEC position;
	InputDevice* iDevice;

public:
	View();
	~View();
	bool Initialize(InputDevice* input, GAME_FLT x, GAME_FLT y);
	void Update(GAME_FLT gameTime);
};
