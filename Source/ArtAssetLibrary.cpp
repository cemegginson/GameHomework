#include <iostream>
#include "ArtAssetLibrary.h"

ArtAssetLibrary::ArtAssetLibrary() { gDevice = nullptr; }

ArtAssetLibrary::~ArtAssetLibrary() {}

bool ArtAssetLibrary::LoadAssets() {
	library.insert(
	    std::pair<std::string, Texture*>("Carrier", new Texture()));
	library.at("Carrier")->Initialize(gDevice->getRenderer, "./Assets/Images/t_carrier.png");

	library.insert(std::pair<std::string, Texture*>("Infantry", new Texture()));
	library.at("Infantry")->Initialize(gDevice->getRenderer(), "./Assets/Images/t_infantry.png");

	return true;
}

Texture* ArtAssetLibrary::Search(std::string key) {
	/*
		auto iter = library.find(key);
		if(iter != library.end()){
			return iter->second;
		}
	*/
	return library.at(key);
}
