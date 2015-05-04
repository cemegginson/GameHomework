#pragma once

#include <string>
#include "ArtAssetLibrary.h"
#include <Box2D/Box2D.h>
#include "InputDevice.h"
#include "Component.h"
#include "pugixml.hpp"
#include "Timer.h"

// Component Classes
#include "Bullet.h"
#include "Carrier.h"
#include "Infantry.h"
#include "Player.h"
#include "Rock.h"

class ComponentFactory {
protected:
	// GraphicsDevice* graphics_device_;
	// ArtAssetLibrary* art_library_;
	// b2World* world_;
	// Timer* timer__;

public:
	ComponentFactory();
	~ComponentFactory();
	virtual Component* Create(pugi::xml_node) = 0;
};

class CarrierFactory : ComponentFactory {
protected:
public:
	CarrierFactory();
	~CarrierFactory();
	Carrier* Create(pugi::xml_node);
};

class InfantryFactory : ComponentFactory {
protected:
public:
	InfantryFactory();
	~InfantryFactory();
	Infantry* Create(pugi::xml_node);
};

class PlayerFactory : ComponentFactory {
protected:
	InputDevice* iDevice;
public:
	PlayerFactory();
	~PlayerFactory();
	Player* Create(pugi::xml_node);
};

// class RockFactory : ComponentFactory {
// protected:
// public:
// 	RockFactory();
// 	~RockFactory();
// 	Rock* Create(pugi::xml_node);
// };
