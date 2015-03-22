#include "Game.h"
#include "pugixml.hpp"
#include <iostream>

Game::Game() {
	gLibrary = nullptr;
	aLibrary = nullptr;
	gDevice = nullptr;
	iDevice = nullptr;
	fps = 0;
	gameTime = 0;
	view = nullptr;
}

Game::~Game() {
	delete gLibrary;
	delete aLibrary;
	delete gDevice;
	delete iDevice;
	delete view;
}

bool Game::Initialize(GraphicsDevice* graphics, InputDevice* input,
		      GAME_INT framerate) {
	gDevice = graphics;
	aLibrary = new ArtAssetLibrary();
	aLibrary->LoadAssets(gDevice);
	iDevice = input;
	fps = framerate;
	timer.Initialize(fps);
	gLibrary = new GameAssetLibrary();
	gLibrary->AddFactory("Infantry",
			     (ObjectFactory*)new InfantryFactory(aLibrary));
	gLibrary->AddFactory("Carrier",
			     (ObjectFactory*)new CarrierFactory(aLibrary));
	return true;
}

void Game::Reset() {
	delete view;
	for (auto iter = objects.begin(); iter <= objects.end(); iter++) {
		//delete *iter;
	}
	// objects.erase(objects.begin(), objects.end());
}

bool Game::LoadLevel(std::string file) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(file.c_str());
	if (result) {
		pugi::xml_node Level = doc.child("Level");
		for (pugi::xml_node child : Level.children("GameAsset")) {
			gLibrary->Search(child.attribute("name").value())
			    ->Create(child);
		}
	}
	return true;
}

void Game::Run() {
	this->Update();
	this->Draw();
}

void Game::Update() {
	for (auto obj : objects) {
		obj->Update(timer.getTicks() / 1000.0);
	}
}

void Game::Draw() {
	for (auto obj : objects) {
		obj->Draw(timer.getTicks() / 1000.0, view);
	}
}
