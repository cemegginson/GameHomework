#pragma once

#include "InputDevice.h"
#include "Definitions.h"

class View {
protected:
	float32 x;
	float32 y;
	GAME_VEC position;
	InputDevice* iDevice;

public:
	View();
	~View();
	bool Initialize(InputDevice* input, float32 x, float32 y);
	void Update(float32 gameTime);
	GAME_VEC getPosition();
};
