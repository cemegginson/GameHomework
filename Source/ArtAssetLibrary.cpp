#include <iostream>
#include "ArtAssetLibrary.h"

ArtAssetLibrary::ArtAssetLibrary() { gDevice = nullptr; }

ArtAssetLibrary::~ArtAssetLibrary() {}

bool ArtAssetLibrary::LoadAssets(GraphicsDevice* graphics) {
	gDevice = graphics;

	// Bullet
	library.insert(std::pair<std::string, Texture*>("Bullet", new Texture()));
	std::string bull = "./Assets/Images/t_bullet.png";
	library.at("Bullet")->Initialize(gDevice->GetRenderer(), bull);

	// Carrier
	library.insert(std::pair<std::string, Texture*>("Carrier", new Texture()));
	std::string carr = "./Assets/Images/t_carrier.png";
	library.at("Carrier")->Initialize(gDevice->GetRenderer(), carr);

	// Infantry
	library.insert(std::pair<std::string, Texture*>("Infantry", new Texture()));
	std::string inf = "./Assets/Images/t_infantry.png";
	library.at("Infantry")->Initialize(gDevice->GetRenderer(), inf);

	// Player
	library.insert(std::pair<std::string, Texture*>("Player", new Texture()));
	std::string pl = "./Assets/Images/t_player.png";
	library.at("Player")->Initialize(gDevice->GetRenderer(), pl);

	// Rock
	library.insert(std::pair<std::string, Texture*>("Rock", new Texture()));
	std::string rock = "./Assets/Images/t_rock.png";
	library.at("Rock")->Initialize(gDevice->GetRenderer(), rock);

	return true;
}

Texture* ArtAssetLibrary::Search(std::string key) {
	return library.at(key);
}
