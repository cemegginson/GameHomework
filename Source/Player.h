#include "Component.h"

class Player : public Component {
protected:

public:
	Player();
	~Player();
	Update();
}

// #pragma once
//
// #include <string>
// #include <list>
// #include "ArtAssetLibrary.h"
// #include "Bullet.h"
// #include "Definitions.h"
// #include "Object.h"
//
// class Player : public Object {
// protected:
// 	ArtAssetLibrary* aLibrary;
// 	std::list<Bullet*> bullets;
// 	InputDevice* iDevice;
// 	uint32 travel;
// 	uint32 radius;
// 	vector2 center;
// 	float32 rotation;
// 	float32 lastfiretime;
//
// 	b2CircleShape shape;
//     b2FixtureDef shapefd;
// public:
// 	Player();
// 	~Player();
// 	void Update(float32);
// 	void Draw(float32, View*);
// 	void Initialize(GraphicsDevice*, Texture*, ArtAssetLibrary*, b2World*, vector2, float32);
// 	void setInput(InputDevice*);
// };
