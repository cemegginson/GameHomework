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
	float32 life;

public:
	Bullet();
	~Bullet();
	void Update(float32);
	void Render(float32, View*);
	int GetLife();
	void Initialize(GraphicsDevice*, Texture*, b2World*, Vector2, Vector2);
};
