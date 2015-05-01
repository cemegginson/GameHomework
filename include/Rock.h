#pragma once

#include <string>
#include "Definitions.h"
#include "Object.h"
#include "View.h"
#include "ArtAssetLibrary.h"
#include <Box2D/Box2D.h>

class Rock : public Object {
protected:
	b2CircleShape shape;
    b2FixtureDef shapefd;

public:
	Rock();
	~Rock();
	void Update(float32);
	void Render(float32, View*);
	void Initialize(GraphicsDevice*, Texture*, b2World*, Vector2, float32);
};
