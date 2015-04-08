#pragma once

#include <string>
#include <list>
#include "ArtAssetLibrary.h"
#include "Bullet.h"
#include "Definitions.h"
#include "Object.h"

class Player : public Object {
protected:
	ArtAssetLibrary* aLibrary;
	std::list<Bullet*> bullets;
	InputDevice* iDevice;
	GAME_INT travel;
	GAME_INT radius;
	GAME_VEC center;
	GAME_FLT rotation;
	GAME_FLT lastfiretime;

	b2CircleShape shape; 
    b2FixtureDef shapefd;
public:
	Player();
	~Player();
	void Update(GAME_FLT);
	void Draw(GAME_FLT, View*);
	void Initialize(GraphicsDevice*, Texture*, ArtAssetLibrary*, b2World*, GAME_VEC, GAME_FLT);
	void setInput(InputDevice*);
};
