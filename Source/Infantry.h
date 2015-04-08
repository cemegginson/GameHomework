#pragma once

#include <string>
#include "Definitions.h"
#include "Object.h"
#include "ArtAssetLibrary.h"

class Infantry : public Object {
protected:
	b2CircleShape shape; 
    b2FixtureDef shapefd;
	GAME_FLT rotation;
	int w, h;

public:
	Infantry();
	~Infantry();
	void Update(GAME_FLT);
	void Draw(GAME_FLT, View*);
	void Initialize(GraphicsDevice*, Texture*, b2World*, GAME_VEC, GAME_FLT);
};
