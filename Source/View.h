#pragma once

class View {
      protected:
	InputDevice* iDevice;
	GAME_VEC position;

      public:
	View();
	~View();
	bool Initialize(InputDevice* input, GAME_FLT x, GAME_FLT y);
	void Update(GAME_FLT gameTime);
}
