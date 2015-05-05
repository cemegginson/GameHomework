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
#include "Rigidbody.h"
#include "Sprite.h"

class ComponentFactory {
protected:

public:
	ComponentFactory();
	~ComponentFactory();
	virtual Component* Create(std::shared_ptr<Actor>, pugi::xml_node) = 0;
};

class CarrierFactory : ComponentFactory {
protected:
public:
	CarrierFactory();
	~CarrierFactory();
	Carrier* Create(std::shared_ptr<Actor>, pugi::xml_node);
};

class InfantryFactory : ComponentFactory {
protected:
public:
	InfantryFactory();
	~InfantryFactory();
	Infantry* Create(std::shared_ptr<Actor>, pugi::xml_node);
};

class PlayerFactory : ComponentFactory {
protected:
	InputDevice* input_device_;

public:
	PlayerFactory(InputDevice*);
	~PlayerFactory();
	Player* Create(std::shared_ptr<Actor>, pugi::xml_node);
};

class RigidbodyFactory : ComponentFactory {
protected:
	b2World* world_;

public:
	RigidbodyFactory(b2World*);
	~RigidbodyFactory();
	Rigidbody* Create(std::shared_ptr<Actor>, pugi::xml_node);
};

class SpriteFactory : ComponentFactory {
protected:
	GraphicsDevice* graphics_device_;
	ArtAssetLibrary* art_library_;

public:
	SpriteFactory(GraphicsDevice*, ArtAssetLibrary*);
	~SpriteFactory();
	Sprite* Create(std::shared_ptr<Actor>, pugi::xml_node);
};
