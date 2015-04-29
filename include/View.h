#pragma once

#include "InputDevice.h"
#include "Definitions.h"

class View {
protected:
	float32 x;
	float32 y;
	vector2 position;
	InputDevice* iDevice;

public:
	View();
	~View();
	bool Initialize(InputDevice* input, float32 x, float32 y);
	void Update(float32 gameTime);
	vector2 getPosition();
};
