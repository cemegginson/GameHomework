#pragma once

class View {
      protected:
	InputDevice* iDevice;
	GAME_VEC position;

      public:
	View();
	~View();
	bool Initialize(InputDevice*, GAME_FLT x, GAME_FLT y);
	void Update(GAME_FLT gameTime);
}
