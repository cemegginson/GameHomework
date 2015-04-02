#include <stdlib.h>
#include <string>
#include "Factory.h"
#include "pugixml.hpp"
#include "Infantry.h"
#include "Carrier.h"

#include <iostream>

ObjectFactory::ObjectFactory() {
	aLibrary = nullptr;
}

ObjectFactory::ObjectFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib) {
	gDevice = gDev;
	aLibrary = aLib;
}

ObjectFactory::~ObjectFactory() {}

InfantryFactory::InfantryFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib) : ObjectFactory(gDev, aLib) {}

InfantryFactory::~InfantryFactory() {}

Object* InfantryFactory::Create(pugi::xml_node tag) {
	Object* infantry = new Infantry();
	GAME_VEC vec;
	GAME_FLT ang;
	std::string name;
	name = tag.attribute("name").value();
	vec.x = stof(tag.attribute("x").value());
	vec.y = stof(tag.attribute("y").value());
	ang = atof(tag.attribute("angle").value());
	infantry->Initialize(gDevice, aLibrary->Search(name), vec, ang);
	return infantry;
}

CarrierFactory::CarrierFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib) : ObjectFactory(gDev, aLib) {}

CarrierFactory::~CarrierFactory() {}

Object* CarrierFactory::Create(pugi::xml_node tag) {
	Object* carrier = new Carrier();
	GAME_VEC vec;
	GAME_FLT ang;
	std::string name;
	name = tag.attribute("name").value();
	vec.x = atof(tag.attribute("x").value());
	vec.y = atof(tag.attribute("y").value());
	ang = atof(tag.attribute("angle").value());
	carrier->Initialize(gDevice, aLibrary->Search(name), vec, ang);
	return carrier;
}
