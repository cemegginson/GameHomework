#include <iostream>
#include "ArtAssetLibrary.h"

ArtAssetLibrary::ArtAssetLibrary() { gDevice = nullptr; }

ArtAssetLibrary::~ArtAssetLibrary() {}

bool ArtAssetLibrary::LoadAssets() {
	if (!library.find("Carrier")->second->Initialize(
		gDevice->getRenderer(), "./Assets/Images/t_carrier.png")) {
		// LogSDLError(std::cerr, "LoadAssets");
		std::cerr << "Something broke" << std::endl;
		return false;
	}
	if (!library.find("Infantry")->second->Initialize(
		gDevice->getRenderer(), "./Assets/Images/t_infantry.png")) {
		// LogSDLError(std::cerr, "LoadAssets");
		std::cerr << "Something broke" << std::endl;
		return false;
	}
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