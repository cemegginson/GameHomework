#pragma once

#include <string>
#include <map>
#include "Texture.h"

class ArtAssetLibrary {
protected:
	static std::map<std::string, Texture*> library;

public:
	ArtAssetLibrary();
	~ArtAssetLibrary();
	Texture* Search(std::string key);
};
