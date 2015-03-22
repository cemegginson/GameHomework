#pragma once

#include <string>
#include "pugixml.hpp"
#include "Object.h"
#include "ArtAssetLibrary.h"

class ObjectFactory {
	protected:
	ArtAssetLibrary* aLibrary;
	public:
	ObjectFactory();
	ObjectFactory(ArtAssetLibrary* aLib);
	~ObjectFactory();
	virtual Object* Create(pugi::xml_node) = 0;
};

class InfantryFactory : ObjectFactory {
	protected:
	public:
	InfantryFactory(ArtAssetLibrary* aLib);
	~InfantryFactory();
	Object* Create(pugi::xml_node);
};

class CarrierFactory : ObjectFactory {
	protected:
	public:
	CarrierFactory(ArtAssetLibrary* aLib);
	~CarrierFactory();
	Object* Create(pugi::xml_node);
};
