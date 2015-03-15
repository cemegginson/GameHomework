#pragma once

class Object {
      protected:
	GraphicsDevice* gDevice;
	InputDevice* iDevice;
	Texture* texture;
	GAME_VEC position;
	GAME_FLT angle;

      public:
	virtual void Update(GAME_FLT gameTime) = 0;
	virtual void Draw(GAME_FLT gameTime, View* view) = 0;
}
