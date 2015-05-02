#pragma once

#include <string>
#include "Definitions.h"
#include "Component.h"
#include "View.h"
#include "ArtAssetLibrary.h"
#include <Box2D/Box2D.h>

class Rock : public Component {
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
