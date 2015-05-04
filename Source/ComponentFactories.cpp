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

std::shared_ptr<Carrier> CarrierFactory::Create(pugi::xml_node node) {}


// InfantryFactory stuff
InfantryFactory::InfantryFactory() : ComponentFactory() {}

InfantryFactory::~InfantryFactory() {}

std::shared_ptr<Infantry> InfantryFactory::Create(pugi::xml_node node) {}


// PlayerFactory stuff
PlayerFactory::PlayerFactory() : ComponentFactory() {}

PlayerFactory::~PlayerFactory() {}

std::shared_ptr<Player> PlayerFactory::Create(pugi::xml_node node) {
	Player* obj = new Player();
	Vector2 vec;
	float32 ang;
	std::string name = tag.attribute("name").value();
	std::string x = tag.attribute("x").value();
	std::string y = tag.attribute("y").value();
	std::string a = tag.attribute("angle").value();
	vec.x = stof(x);
	vec.y = stof(y);
	ang = stof(a);
	obj->Initialize();
	obj->SetInput(iDevice);
	return obj;
}


// RigidbodyFactory stuff
RigidbodyFactory::RigidbodyFactory(b2World* world) : ComponentFactory() {
	world_ = world;
}

RigidbodyFactory::~RigidbodyFactory() {}

std::shared_ptr<Rigidbody> RigidbodyFactory::Create(pugi::xml_node node) {

}


// SpriteFactory stuff
SpriteFactory::SpriteFactory() : ComponentFactory() {}

SpriteFactory::~SpriteFactory() {}

std::shared_ptr<Sprite> SpriteFactory::Create(pugi::xml_node node) {

}
