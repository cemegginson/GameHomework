#include <iostream>
#include <stdlib.h>
#include <string>

#include "ComponentFactories.h"
#include "pugixml.hpp"

// Raw ComponentFactory stuff
ComponentFactory::ComponentFactory() {}

ComponentFactory::~ComponentFactory() {}


// CarrierFactory stuff
CarrierFactory::CarrierFactory() : ComponentFactory() {}

CarrierFactory::~CarrierFactory() {}

std::shared_ptr<Carrier> CarrierFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {}


// InfantryFactory stuff
InfantryFactory::InfantryFactory() : ComponentFactory() {}

InfantryFactory::~InfantryFactory() {}

std::shared_ptr<Infantry> InfantryFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {}


// PlayerFactory stuff
PlayerFactory::PlayerFactory(InputDevice* input_device) : ComponentFactory() {
	input_device_ = input_device;
}

PlayerFactory::~PlayerFactory() {}

std::shared_ptr<Player> PlayerFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	// Player* obj = new Player();
	// Vector2 vec;
	// float32 ang;
	// std::string name = tag.attribute("name").value();
	// std::string x = tag.attribute("x").value();
	// std::string y = tag.attribute("y").value();
	// std::string a = tag.attribute("angle").value();
	// vec.x = stof(x);
	// vec.y = stof(y);
	// ang = stof(a);
	// obj->Initialize();
	// obj->SetInput(iDevice);
	// return obj;
}


// RigidbodyFactory stuff
RigidbodyFactory::RigidbodyFactory(b2World* world) : ComponentFactory() {
	world_ = world;
}

RigidbodyFactory::~RigidbodyFactory() {}

std::shared_ptr<Rigidbody> RigidbodyFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {

}


// SpriteFactory stuff
SpriteFactory::SpriteFactory(GraphicsDevice* graphics_device, ArtAssetLibrary* art_library) : ComponentFactory() {
	graphics_device_ = graphics_device;
	art_library_ = art_library;
}

SpriteFactory::~SpriteFactory() {}

std::shared_ptr<Sprite> SpriteFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	std::shared_ptr<Sprite> new_sprite = new Sprite(std::shared_ptr<Actor> owner);
	std::string texture = node.attribute("texture");
	new_sprite->Initialize(graphics_device_, art_library_->at("texture"));
}
