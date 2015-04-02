#pragma once

#include <string>
#include "Definitions.h"
#include "Object.h"
#include "ArtAssetLibrary.h"

class Player : public Object {
protected:
	ArtAssetLibrary artlib;

public:
	Player();
	~Player();
	void Update(GAME_FLT gameTime);
	void Draw(GAME_FLT gameTime, View* view);
	void Initialize(GraphicsDevice* gDev, Texture* tex, GAME_VEC pos, GAME_FLT ang);
};
