#pragma once

#include <string>
#include <vector>
#include "ArtAssetLibrary.h"
#include "Bullet.h"
#include "Definitions.h"
#include "Object.h"

class Player : public Object {
protected:
	ArtAssetLibrary* aLibrary;
	std::vector<Bullet*> bullets;
	InputDevice* iDevice;
	GAME_INT travel = 2;
	GAME_INT radius = 15;
	GAME_VEC center;
public:
	Player();
	~Player();
	void Update(GAME_FLT);
	void Draw(GAME_FLT, View*);
	void Initialize(GraphicsDevice*, Texture*, ArtAssetLibrary*, GAME_VEC, GAME_FLT);
	void setInput(InputDevice*);
};
