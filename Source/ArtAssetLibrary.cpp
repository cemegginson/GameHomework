#include <iostream>
#include "ArtAssetLibrary.h"

ArtAssetLibrary::ArtAssetLibrary() { graphics_device_ = nullptr; }

ArtAssetLibrary::~ArtAssetLibrary() {}

bool ArtAssetLibrary::LoadAssets(GraphicsDevice* graphics_device) {
	graphics_device_ = graphics_device;

	// Bullet
	library_.insert(std::pair<std::string, Texture*>("Bullet", new Texture()));
	std::string bull = "./Assets/Images/t_bullet.png";
	library_.at("Bullet")->Initialize(graphics_device_->GetRenderer(), bull);

	// Carrier
	library_.insert(std::pair<std::string, Texture*>("Carrier", new Texture()));
	std::string carr = "./Assets/Images/t_carrier.png";
	library_.at("Carrier")->Initialize(graphics_device_->GetRenderer(), carr);

	// Infantry
	library_.insert(std::pair<std::string, Texture*>("Infantry", new Texture()));
	std::string inf = "./Assets/Images/t_infantry.png";
	library_.at("Infantry")->Initialize(graphics_device_->GetRenderer(), inf);

	// Player
	library_.insert(std::pair<std::string, Texture*>("Player", new Texture()));
	std::string pl = "./Assets/Images/t_player.png";
	library_.at("Player")->Initialize(graphics_device_->GetRenderer(), pl);

	// Rock
	library_.insert(std::pair<std::string, Texture*>("Rock", new Texture()));
	std::string rock = "./Assets/Images/t_rock.png";
	library_.at("Rock")->Initialize(graphics_device_->GetRenderer(), rock);

	return true;
}

Texture* ArtAssetLibrary::Search(std::string key) {
	return library_.at(key);
}
