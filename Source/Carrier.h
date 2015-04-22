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
	vector2 center;
	float32 rotation;
	int radius;
	int w, h;

public:
	Carrier();
	~Carrier();
	void Update(float32);
	void Draw(float32, View*);
	void Initialize(GraphicsDevice*, Texture*, b2World*, vector2, float32);
};
