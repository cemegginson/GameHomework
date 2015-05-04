#include <iostream>

// #include "ContactListener.h"
#include "Game.h"
#include "GameFunctions.h"
#include "pugixml.hpp"

Game::Game() {
	component_factories_ = nullptr;
	art_library_ = nullptr;
	graphics_device_ = nullptr;
	input_device_ = nullptr;
	timer_ = nullptr;
	view_ = nullptr;
}

Game::~Game() {
	delete component_factories_;
	delete art_library_;
	delete graphics_device_;
	delete input_device_;
	delete view_;
}

bool Game::Initialize(GraphicsDevice* graphics_device, InputDevice* input_device) {
	graphics_device_ = graphics_device;
	input_device_ = input_device;

	// Load sprites
	art_library_ = new ArtAssetLibrary();
	art_library_->LoadAssets(graphics_device_, view_);

	view_ = new View();
	view_->Initialize(input_device_, 0, 0);

	timer_ = new Timer();
	timer_->start();

	// Initialize Physics world
	const b2Vec2 gravity(0, 0);
	world_ = new b2World(gravity);

	// Create Factories
	component_factories_ = new ComponentLibrary();
	component_factories_->AddFactory("Carrier", (ComponentFactory*)new CarrierFactory());
	component_factories_->AddFactory("Infantry", (ComponentFactory*)new InfantryFactory());
	component_factories_->AddFactory("Player", (ComponentFactory*)new PlayerFactory(input_device_));

	// ContactListener* contact_listener = new ContactListener();
	// world_->SetContactListener(contact_listener);

	return true;
}

void Game::Reset() {
	if(!actors_.empty()){
		for (auto iter = actors_.begin(); iter <= actors_.end(); iter++) {
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
		for (pugi::xml_node child : Level.children("Component")) {
			name = child.attribute("name").value();
			components_.push_back((Component*)component_factories_->Search(name)->Create(child));
		}
	}
	return true;
}

void Game::Run() {
	timer_->Update();
	Update(timer_->DeltaTime());
	graphics_device_->Render();
}

void Game::Update(float32 delta_time) {
	// Update View position
	view_->Update(delta_time);

	// Cycle through every objects' Update method
	for (auto iter = actors_.begin(); iter != actors_.end(); ++iter) {
		(*iter)->Update(delta_time);
	}

	world_->Step(.01, 8, 3);
}
