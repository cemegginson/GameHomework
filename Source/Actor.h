#pragma once

#include <vector>

#include "Component.h"
#include "Definitions.h"
#include "InputDevice.h"
#include "View.h"

class Actor {
protected:
	// GraphicsDevice* gDevice;
	// InputDevice* iDevice;
	// Texture* texture;
	// vector2 position;
	// float32 angle;
    std::vector<Component> components;

public:
	Actor();
	virtual ~Actor();
	virtual void Update(float32) = 0;
	// virtual void Render(float32, View*) = 0;
	// virtual void Initialize(GraphicsDevice* graphics, Texture* tex,
	// 			vector2 pos, float32 ang) = 0;
};
