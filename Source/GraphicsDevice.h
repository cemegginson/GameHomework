#pragma once

class GraphicsDevice {
      protected:
    int Width;
    int Height;
    SDL_Window* window;
    SDL_Renderer* renderer;

      public:
	GraphicsDevice();
	GraphicsDevice(int ScreenWidth, int Screen Height);
	~GraphicsDevice();
	bool Initialize();
    int Width();
    int Height();
}
