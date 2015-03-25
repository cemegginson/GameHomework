#include <iostream>
#include "ArtAssetLibrary.h"

ArtAssetLibrary::ArtAssetLibrary() { gDevice = nullptr; }

ArtAssetLibrary::~ArtAssetLibrary() {}

bool ArtAssetLibrary::LoadAssets(GraphicsDevice* graphics) {
	gDevice = graphics;
	library.insert(
	    std::pair<std::string, Texture*>("Carrier", new Texture()));
	std::string carr = "./Assets/Images/t_carrier.png";
	library.at("Carrier")->Initialize(gDevice->getRenderer(), carr);

	library.insert(std::pair<std::string, Texture*>("Infantry", new Texture()));
	std::string inf = "./Assets/Images/t_infantry.png";
	library.at("Infantry")->Initialize(gDevice->getRenderer(), inf);

	return true;
}

Texture* ArtAssetLibrary::Search(std::string key) {
	return library.at(key);
}
