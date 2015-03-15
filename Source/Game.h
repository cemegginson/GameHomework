#pragma once

class Game {
      protected:
	GameAssetLibrary* gLibrary;
	ArtAssetLibrary* aLibrary;
	GraphicsDevice* gDevice;
	InputDevice* iDevice;
	Timer timer;
	GAME_INT fps;
	GAME_FLT gameTime;
	View* view;
	vector<Object*> objects;

      public:
	Game();
	~Game();
	bool Initialize(GraphicsDevice* gDevice, InputDevice* iDevice,
			GAME_INT fps);
	void Reset();
	bool LoadLevel(string file) void Run();
	void Update();
	void Draw();
};
