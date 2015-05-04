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

Carrier* CarrierFactory::Create(pugi::xml_node tag) {
	Carrier* obj = new Carrier();
	Vector2 vec;
	float32 ang;
	std::string name = tag.attribute("name").value();
	std::string x = tag.attribute("x").value();
	std::string y = tag.attribute("y").value();
	std::string a = tag.attribute("angle").value();
	vec.x = stof(x);
	vec.y = stof(y);
	ang = stof(a);
	obj->Initialize(graphics_device_, aLibrary->Search(name), world_, vec, ang);
	return obj;
}


// InfantryFactory stuff
InfantryFactory::InfantryFactory() : ComponentFactory() {}

InfantryFactory::~InfantryFactory() {}

Infantry* InfantryFactory::Create(pugi::xml_node tag) {
	Infantry* obj = new Infantry();
	Vector2 vec;
	float32 ang;
	std::string name = tag.attribute("name").value();
	std::string x = tag.attribute("x").value();
	std::string y = tag.attribute("y").value();
	std::string a = tag.attribute("angle").value();
	vec.x = stof(x);
	vec.y = stof(y);
	ang = stof(a);
	obj->Initialize(graphics_device_, aLibrary->Search(name), world_, vec, ang);
	return obj;
}


// PlayerFactory stuff
PlayerFactory::PlayerFactory() : ComponentFactory() {}

PlayerFactory::~PlayerFactory() {}

Player* PlayerFactory::Create(pugi::xml_node tag) {
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

RigidbodyFactory::RigidbodyFactory() : ComponentFactory() {}

RigidbodyFactory::~RigidbodyFactory() {}

Rigidbody* RigidbodyFactory::Create(pugi::xml_node tag) {

}


SpriteFactory::SpriteFactory() : ComponentFactory() {}

SpriteFactory::~SpriteFactory() {}

Sprite* SpriteFactory::Create(pugi::xml_node tag) {

}
// RockFactory::RockFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib, b2World* wor) : ComponentFactory(gDev, aLib, wor) {}
//
// RockFactory::~RockFactory() {}
//
// Rock* RockFactory::Create(pugi::xml_node tag) {
// 	Rock* obj = new Rock();
// 	Vector2 vec;
// 	float32 ang;
// 	std::string name = tag.attribute("name").value();
// 	std::string x = tag.attribute("x").value();
// 	std::string y = tag.attribute("y").value();
// 	std::string a = tag.attribute("angle").value();
// 	vec.x = stof(x);
// 	vec.y = stof(y);
// 	ang = stof(a);
// 	obj->Initialize(graphics_device_, aLibrary->Search(name), world_, vec, ang);
// 	return obj;
// }
