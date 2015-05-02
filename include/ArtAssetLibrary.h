#pragma once

#include <string>
#include <map>
#include "Texture.h"
#include "GraphicsDevice.h"

class ArtAssetLibrary {
protected:
	std::map<std::string, Texture*> library_;
	GraphicsDevice* graphics_device_;

public:
	ArtAssetLibrary();
	~ArtAssetLibrary();
	bool LoadAssets(GraphicsDevice*);
	Texture* Search(std::string);
};
