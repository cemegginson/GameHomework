#pragma once

#include <string>
#include <Box2D/Box2D.h>
#include "Definitions.h"
#include "GraphicsDevice.h"
#include "InputDevice.h"
#include "Texture.h"
#include "View.h"

class Actor {
protected:
	GraphicsDevice* gDevice;
	InputDevice* iDevice;
	Texture* texture;
	GAME_VEC position;
	GAME_FLT angle;

public:
	Actor();
	virtual ~Actor();
	virtual void Update(GAME_FLT) = 0;
	virtual void Draw(GAME_FLT, View*) = 0;
	// virtual void Initialize(GraphicsDevice* graphics, Texture* tex,
	// 			GAME_VEC pos, GAME_FLT ang) = 0;
};
