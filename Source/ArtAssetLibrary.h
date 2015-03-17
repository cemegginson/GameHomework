#pragma once

class ArtAssetLibrary {
protected:
	map<std::string, Texture*> library;

public:
	ArtAssetLibrary();
	~ArtAssetLibrary();
	Texture* Search(std::string key);
}
