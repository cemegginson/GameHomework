#pragma once

#include <string>
#include "ArtAssetLibrary.h"
#include "InputDevice.h"
#include "Object.h"
#include "pugixml.hpp"

// Object Classes
#include "Carrier.h"
#include "Infantry.h"
#include "Player.h"
#include "Rock.h"

class ObjectFactory {
protected:
	GraphicsDevice* gDevice;
	ArtAssetLibrary* aLibrary;

public:
	ObjectFactory();
	ObjectFactory(GraphicsDevice*, ArtAssetLibrary*);
	~ObjectFactory();
	virtual Object* Create(pugi::xml_node) = 0;
};

class CarrierFactory : ObjectFactory {
protected:
public:
	CarrierFactory(GraphicsDevice*, ArtAssetLibrary*);
	~CarrierFactory();
	Carrier* Create(pugi::xml_node);
};

class InfantryFactory : ObjectFactory {
protected:
public:
	InfantryFactory(GraphicsDevice*, ArtAssetLibrary*);
	~InfantryFactory();
	Infantry* Create(pugi::xml_node);
};

class PlayerFactory : ObjectFactory {
protected:
	InputDevice* iDevice;
public:
	PlayerFactory(GraphicsDevice*, ArtAssetLibrary*, InputDevice*);
	~PlayerFactory();
	Player* Create(pugi::xml_node);
};

class RockFactory : ObjectFactory {
protected:
public:
	RockFactory(GraphicsDevice*, ArtAssetLibrary*);
	~RockFactory();
	Rock* Create(pugi::xml_node);
};
