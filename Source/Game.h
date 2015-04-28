#pragma once

#include <list>
#include <string>

#include "Box2D/Box2D.h"

#include "GameAssetLibrary.h"
#include "ArtAssetLibrary.h"
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
	// std::vector<Object*> objects;
	std::list<std::shared_ptr<Actor>> actors;
	b2World* world;

public:
	Game();
	~Game();
	bool Initialize(GraphicsDevice* graphics, InputDevice* input);
	void Reset();
	bool LoadLevel(std::string file);
	void Run();
	void Update();
	void Draw();
};
