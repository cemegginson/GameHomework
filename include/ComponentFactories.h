#pragma once

#include <memory>
#include <string>

#include "Box2D/Box2D.h"
#include "pugixml.hpp"

#include "ArtAssetLibrary.h"
#include "Bullet.h"
#include "Carrier.h"
#include "Component.h"
#include "Infantry.h"
#include "InputDevice.h"
#include "Player.h"

class ComponentFactory {
protected:

public:
	ComponentFactory();
	~ComponentFactory();
	virtual std::shared_ptr<Component> Create(pugi::xml_node) = 0;
};

class CarrierFactory : ComponentFactory {
protected:
public:
	CarrierFactory();
	~CarrierFactory();
	std::shared_ptr<Carrier> Create(pugi::xml_node);
};

class InfantryFactory : ComponentFactory {
protected:
public:
	InfantryFactory();
	~InfantryFactory();
	std::shared_ptr<Infantry> Create(pugi::xml_node);
};

class PlayerFactory : ComponentFactory {
protected:
	InputDevice* input_device_;

public:
	PlayerFactory();
	~PlayerFactory();
	std::shared_ptr<Player> Create(pugi::xml_node);
};

class RigidbodyFactory : ComponentFactory {
protected:
	b2World* world_;

public:
	RigidbodyFactory(b2World*);
	~RigidbodyFactory();
	std::shared_ptr<Rigidbody> Create(pugi::xml_node);
};

class SpriteFactory : ComponentFactory {
protected:
public:
	SpriteFactory();
	~SpriteFactory();
	std::shared_ptr<Sprite> Create(pugi::xml_node);
};

// class RockFactory : ComponentFactory {
// protected:
// public:
// 	RockFactory();
// 	~RockFactory();
// 	Rock* Create(pugi::xml_node);
// };
