#include <iostream>
#include <stdlib.h>
#include <string>
#include "Factory.h"
#include "pugixml.hpp"

// Object Classes
#include "Carrier.h"
#include "Infantry.h"
#include "Player.h"
#include "Rock.h"

ObjectFactory::ObjectFactory() {
	aLibrary = nullptr;
}

ObjectFactory::ObjectFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib) {
	gDevice = gDev;
	aLibrary = aLib;
}

ObjectFactory::~ObjectFactory() {}

CarrierFactory::CarrierFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib) : ObjectFactory(gDev, aLib) {}

CarrierFactory::~CarrierFactory() {}

Object* CarrierFactory::Create(pugi::xml_node tag) {
	Object* obj = new Carrier();
	GAME_VEC vec;
	GAME_FLT ang;
	std::string name = tag.attribute("name").value();
	std::string x = tag.attribute("x").value();
	std::string y = tag.attribute("y").value();
	std::string a = tag.attribute("angle").value();
	vec.x = stof(x);
	vec.y = stof(y);
	ang = stof(a);
	obj->Initialize(gDevice, aLibrary->Search(name), vec, ang);
	return obj;
}

InfantryFactory::InfantryFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib) : ObjectFactory(gDev, aLib) {}

InfantryFactory::~InfantryFactory() {}

Object* InfantryFactory::Create(pugi::xml_node tag) {
	Object* obj = new Infantry();
	GAME_VEC vec;
	GAME_FLT ang;
	std::string name = tag.attribute("name").value();
	std::string x = tag.attribute("x").value();
	std::string y = tag.attribute("y").value();
	std::string a = tag.attribute("angle").value();
	vec.x = stof(x);
	vec.y = stof(y);
	ang = stof(a);
	obj->Initialize(gDevice, aLibrary->Search(name), vec, ang);
	return obj;
}

PlayerFactory::PlayerFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib) : ObjectFactory(gDev, aLib) {}

PlayerFactory::~PlayerFactory() {}

Object* PlayerFactory::Create(pugi::xml_node tag) {
	Object* obj = new Player();
	GAME_VEC vec;
	GAME_FLT ang;
	std::string name = tag.attribute("name").value();
	std::string x = tag.attribute("x").value();
	std::string y = tag.attribute("y").value();
	std::string a = tag.attribute("angle").value();
	vec.x = stof(x);
	vec.y = stof(y);
	ang = stof(a);
	obj->Initialize(gDevice, aLibrary->Search(name), vec, ang);
	return obj;
}

RockFactory::RockFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib) : ObjectFactory(gDev, aLib) {}

RockFactory::~RockFactory() {}

Object* RockFactory::Create(pugi::xml_node tag) {
	Object* obj = new Rock();
	GAME_VEC vec;
	GAME_FLT ang;
	std::string name = tag.attribute("name").value();
	std::string x = tag.attribute("x").value();
	std::string y = tag.attribute("y").value();
	std::string a = tag.attribute("angle").value();
	vec.x = stof(x);
	vec.y = stof(y);
	ang = stof(a);
	obj->Initialize(gDevice, aLibrary->Search(name), vec, ang);
	return obj;
}
