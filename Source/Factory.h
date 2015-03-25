#pragma once

#include <string>
#include "pugixml.hpp"
#include "Object.h"
#include "ArtAssetLibrary.h"

class ObjectFactory {
	protected:
	GraphicsDevice* gDevice;
	ArtAssetLibrary* aLibrary;
	public:
	ObjectFactory();
	ObjectFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib);
	~ObjectFactory();
	virtual Object* Create(pugi::xml_node) = 0;
};

class InfantryFactory : ObjectFactory {
	protected:
	public:
	InfantryFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib);
	~InfantryFactory();
	Object* Create(pugi::xml_node);
};

class CarrierFactory : ObjectFactory {
	protected:
	public:
	CarrierFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib);
	~CarrierFactory();
	Object* Create(pugi::xml_node);
};
