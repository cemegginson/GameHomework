#pragma once

#include <vector>
#include <string>
#include "GameAssetLibrary.h"
#include "ArtAssetLibrary.h"
#include "Box2D/Box2D.h"
#include "Timer.h"
#include "View.h"
#include "Object.h"

class Game {
protected:
	GameAssetLibrary* gLibrary;
	ArtAssetLibrary* aLibrary;
	GraphicsDevice* gDevice;
	InputDevice* iDevice;
	Timer* timer;
	uint32 fps;
	float32 gameTime;
	View* view;
	std::vector<Object*> objects;
	b2World* world;

public:
	Game();
	~Game();
	bool Initialize(GraphicsDevice* graphics, InputDevice* input,
			uint32 fps);
	void Reset();
	bool LoadLevel(std::string file);
	void Run();
	void Update();
	void Draw();
};
