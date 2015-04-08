#include <iostream>
#include <stdlib.h>
#include <string>
#include "Factory.h"
#include "pugixml.hpp"

ObjectFactory::ObjectFactory() {
	aLibrary = nullptr;
}

ObjectFactory::ObjectFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib, b2World* wor) {
	gDevice = gDev;
	aLibrary = aLib;
	world = wor;
}

ObjectFactory::~ObjectFactory() {}

CarrierFactory::CarrierFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib, b2World* wor) : ObjectFactory(gDev, aLib, wor) {}

CarrierFactory::~CarrierFactory() {}

Carrier* CarrierFactory::Create(pugi::xml_node tag) {
	Carrier* obj = new Carrier();
	GAME_VEC vec;
	GAME_FLT ang;
	std::string name = tag.attribute("name").value();
	std::string x = tag.attribute("x").value();
	std::string y = tag.attribute("y").value();
	std::string a = tag.attribute("angle").value();
	vec.x = stof(x);
	vec.y = stof(y);
	ang = stof(a);
	obj->Initialize(gDevice, aLibrary->Search(name), world, vec, ang);
	return obj;
}

InfantryFactory::InfantryFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib, b2World* wor) : ObjectFactory(gDev, aLib, wor) {}

InfantryFactory::~InfantryFactory() {}

Infantry* InfantryFactory::Create(pugi::xml_node tag) {
	Infantry* obj = new Infantry();
	GAME_VEC vec;
	GAME_FLT ang;
	std::string name = tag.attribute("name").value();
	std::string x = tag.attribute("x").value();
	std::string y = tag.attribute("y").value();
	std::string a = tag.attribute("angle").value();
	vec.x = stof(x);
	vec.y = stof(y);
	ang = stof(a);
	obj->Initialize(gDevice, aLibrary->Search(name), world, vec, ang);
	return obj;
}

PlayerFactory::PlayerFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib, b2World* wor, InputDevice* iDev) : ObjectFactory(gDev, aLib, wor) {
	iDevice = iDev;
}

PlayerFactory::~PlayerFactory() {}

Player* PlayerFactory::Create(pugi::xml_node tag) {
	Player* obj = new Player();
	GAME_VEC vec;
	GAME_FLT ang;
	std::string name = tag.attribute("name").value();
	std::string x = tag.attribute("x").value();
	std::string y = tag.attribute("y").value();
	std::string a = tag.attribute("angle").value();
	vec.x = stof(x);
	vec.y = stof(y);
	ang = stof(a);
	obj->Initialize(gDevice, aLibrary->Search(name), aLibrary, world, vec, ang);
	obj->setInput(iDevice);
	return obj;
}

RockFactory::RockFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib, b2World* wor) : ObjectFactory(gDev, aLib, wor) {}

RockFactory::~RockFactory() {}

Rock* RockFactory::Create(pugi::xml_node tag) {
	Rock* obj = new Rock();
	GAME_VEC vec;
	GAME_FLT ang;
	std::string name = tag.attribute("name").value();
	std::string x = tag.attribute("x").value();
	std::string y = tag.attribute("y").value();
	std::string a = tag.attribute("angle").value();
	vec.x = stof(x);
	vec.y = stof(y);
	ang = stof(a);
	obj->Initialize(gDevice, aLibrary->Search(name), world, vec, ang);
	return obj;
}
