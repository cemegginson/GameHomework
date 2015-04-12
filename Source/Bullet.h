#pragma once

#include <string>
#include "Definitions.h"
#include "Object.h"
#include "View.h"
#include "ArtAssetLibrary.h"
#include <Box2D/Box2D.h>

class Bullet : public Object {
protected:
	b2Vec2 velocity;
	b2CircleShape shape; 
    b2FixtureDef shapefd;
	int w, h;
	GAME_FLT life;

public:
	Bullet();
	~Bullet();
	void Update(GAME_FLT);
	void Draw(GAME_FLT, View*);
	int GetLife();
	void Initialize(GraphicsDevice*, Texture*, b2World*, GAME_VEC, GAME_VEC);
};
