#pragma once

#include <string>
#include "Definitions.h"
#include "Object.h"
#include "View.h"
#include "ArtAssetLibrary.h"

class Carrier : public Object {
	protected:
	ArtAssetLibrary aLibrary;
	GAME_VEC center;
	int radius;

	public:
	Carrier();
	~Carrier();
	void Update(GAME_FLT gameTime);
	void Draw(GAME_FLT gameTime, View* view);
	void Initialize(GraphicsDevice* gDev, Texture* tex, GAME_VEC pos, GAME_FLT ang);
};
