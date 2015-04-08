#pragma once

#include <string>
#include "ArtAssetLibrary.h"
#include "Box2D\Box2D.h"
#include "InputDevice.h"
#include "Object.h"
#include "pugixml.hpp"
#include "Timer.h"

// Object Classes
#include "Bullet.h"
#include "Carrier.h"
#include "Infantry.h"
#include "Player.h"
#include "Rock.h"

class ObjectFactory {
protected:
	GraphicsDevice* gDevice;
	ArtAssetLibrary* aLibrary;
	b2World* world;
	Timer* timer;

public:
	ObjectFactory();
	ObjectFactory(GraphicsDevice*, ArtAssetLibrary*, b2World*);
	~ObjectFactory();
	virtual Object* Create(pugi::xml_node) = 0;
};

class CarrierFactory : ObjectFactory {
protected:
public:
	CarrierFactory(GraphicsDevice*, ArtAssetLibrary*, b2World*);
	~CarrierFactory();
	Carrier* Create(pugi::xml_node);
};

class InfantryFactory : ObjectFactory {
protected:
public:
	InfantryFactory(GraphicsDevice*, ArtAssetLibrary*, b2World*);
	~InfantryFactory();
	Infantry* Create(pugi::xml_node);
};

class PlayerFactory : ObjectFactory {
protected:
	InputDevice* iDevice;
public:
	PlayerFactory(GraphicsDevice*, ArtAssetLibrary*, b2World*, InputDevice*);
	~PlayerFactory();
	Player* Create(pugi::xml_node);
};

class RockFactory : ObjectFactory {
protected:
public:
	RockFactory(GraphicsDevice*, ArtAssetLibrary*, b2World*);
	~RockFactory();
	Rock* Create(pugi::xml_node);
};
