#include "Game.h"
#include "pugixml.hpp"
#include <iostream>

Game::Game() {
	gLibrary = nullptr;
	aLibrary = nullptr;
	gDevice = nullptr;
	iDevice = nullptr;
	timer = nullptr;
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

bool Game::Initialize(GraphicsDevice* graphics, InputDevice* input, GAME_INT framerate) {
	gDevice = graphics;

	aLibrary = new ArtAssetLibrary();
	aLibrary->LoadAssets(graphics);
	iDevice = input;

	view = new View();
	view->Initialize(input, 0, 0);

	fps = framerate;
	timer = new Timer();
	timer->Initialize(fps);

	gLibrary = new GameAssetLibrary();
	gLibrary->AddFactory("Carrier",
			     (ObjectFactory*)new CarrierFactory(gDevice, aLibrary));
	gLibrary->AddFactory("Infantry",
				(ObjectFactory*)new InfantryFactory(gDevice, aLibrary));
	gLibrary->AddFactory("Player",
				(ObjectFactory*)new PlayerFactory(gDevice, aLibrary));
	gLibrary->AddFactory("Rock",
			     (ObjectFactory*)new RockFactory(gDevice, aLibrary));
	return true;
}

void Game::Reset() {
	if(!objects.empty()){
		for (std::vector<Object*>::iterator iter = objects.begin(); iter <= objects.end(); iter++) {
			delete *iter;
		}
	}
}

bool Game::LoadLevel(std::string file) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(file.c_str());
	if (result) {
		pugi::xml_node Level = doc.child("Level");
		std::string name;
		for (pugi::xml_node child : Level.children("GameAsset")) {
			name = child.attribute("name").value();
			objects.push_back(gLibrary->Search(name)->Create(child));
		}
	}
	return true;
}

void Game::Run() {
	timer->start();
	Update();
	Draw();
	timer->fpsRegulate();
}

void Game::Update() {
	// Update View position
	view->Update(timer->getTicks());

	// Cycle through every objects' Update method
	for (std::vector<Object*>::iterator iter = objects.begin(); iter != objects.end(); ++iter) {
		(*iter)->Update(timer->getTicks()/1000.0);
	}
}

void Game::Draw() {
	SDL_RenderClear(gDevice->getRenderer());

	// Cycle through every objects' Draw method
	for (std::vector<Object*>::iterator iter = objects.begin(); iter != objects.end(); ++iter) {
		(*iter)->Draw(timer->getTicks(), view);
	}
	SDL_RenderPresent(gDevice->getRenderer());
}
