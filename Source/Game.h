#pragma once

#include <vector>
#include <string>
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
	GAME_INT fps;
	GAME_FLT gameTime;
	View* view;
	std::vector<Object*> objects;

	public:
	Game();
	~Game();
	bool Initialize(GraphicsDevice* graphics, InputDevice* input,
			GAME_INT fps);
	void Reset();
	bool LoadLevel(std::string file);
	void Run();
	void Update();
	void Draw();
};
