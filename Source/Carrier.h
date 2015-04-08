#pragma once

#include <string>
#include "Definitions.h"
#include "Object.h"
#include "View.h"
#include "ArtAssetLibrary.h"

class Carrier : public Object {
protected:
	b2PolygonShape shape; 
    b2FixtureDef shapefd;
	GAME_VEC center;
	GAME_FLT rotation;
	int radius;
	int w, h;

public:
	Carrier();
	~Carrier();
	void Update(GAME_FLT);
	void Draw(GAME_FLT, View*);
	void Initialize(GraphicsDevice*, Texture*, b2World*, GAME_VEC, GAME_FLT);
};
