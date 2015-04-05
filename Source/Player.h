#pragma once

#include <string>
#include "Definitions.h"
#include "Object.h"
#include "ArtAssetLibrary.h"

class Player : public Object {
protected:
	InputDevice* iDevice;
	GAME_INT travel = 2;
public:
	Player();
	~Player();
	void Update(GAME_FLT gameTime);
	void Draw(GAME_FLT gameTime, View* view);
	void Initialize(GraphicsDevice*, Texture*, GAME_VEC, GAME_FLT);
	void setInput(InputDevice*);
};
