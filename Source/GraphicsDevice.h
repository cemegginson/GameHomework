#pragma once

class GraphicsDevice {
      protected:
      public:
	GraphicsDevice();
	GraphicsDevice(int ScreenWidth, int Screen Height);
	~GraphicsDevice();
	bool Initialize();
}
