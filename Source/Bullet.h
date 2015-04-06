#pragma once

#include <string>
#include "Definitions.h"
#include "Object.h"
#include "View.h"
#include "ArtAssetLibrary.h"

class Bullet : public Object {
protected:
	GAME_VEC velocity;

public:
	Bullet();
	~Bullet();
	void Update(GAME_FLT gameTime);
	void Draw(GAME_FLT gameTime, View* view);
	void Initialize(GraphicsDevice*, Texture*, GAME_VEC, GAME_VEC);
};
