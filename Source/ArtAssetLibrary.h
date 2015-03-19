#pragma once

#include <string>
#include <map>
#include "Texture.h"
#include "GraphicsDevice.h"

class ArtAssetLibrary {
protected:
	std::map<std::string, Texture*> library;
	GraphicsDevice* gDevice;

public:
	ArtAssetLibrary();
	~ArtAssetLibrary();
	bool LoadAssets();
	Texture* Search(std::string key);
};
