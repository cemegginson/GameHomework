#include <iostream>
#include <stdlib.h>
#include <string>

#include "ComponentFactories.h"
#include "pugixml.hpp"

// Raw ComponentFactory stuff
ComponentFactory::ComponentFactory() {}

ComponentFactory::~ComponentFactory() {}


// CarrierFactory stuff
CarrierFactory::CarrierFactory() : ComponentFactory() {}

CarrierFactory::~CarrierFactory() {}

Carrier* CarrierFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	Carrier* carrier = new Carrier(owner);
	return carrier;
}


// InfantryFactory stuff
InfantryFactory::InfantryFactory() : ComponentFactory() {}

InfantryFactory::~InfantryFactory() {}

Infantry* InfantryFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	Infantry* infantry = new Infantry(owner);
	return infantry;
}


// PlayerFactory stuff
PlayerFactory::PlayerFactory(InputDevice* input_device) : ComponentFactory() {
	input_device_ = input_device;
}

PlayerFactory::~PlayerFactory() {}

Player* PlayerFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	Player* player = new Player(owner);
	player->SetInput(input_device_);
	return player;
}


// RigidbodyFactory stuff
RigidbodyFactory::RigidbodyFactory(b2World* world) : ComponentFactory() {
	world_ = world;
}

RigidbodyFactory::~RigidbodyFactory() {}

Rigidbody* RigidbodyFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	Rigidbody* rigidbody = new Rigidbody(owner);

		// bdef.type = b2_dynamicBody;
		// bdef.position.Set(RW2PW(position.x), RW2PW(position.y));
		// bdef.angle = RW2PWAngle(angle);
		// bdef.bullet = true;
		// bdef.angularDamping = 0.1;
		// bdef.linearDamping = 0.1;
		// bdef.linearVelocity = velocity;
		// body = world->CreateBody(&bdef);
		//
		// texture->GetDimensions(&w, &h);
		// shape.m_radius = RW2PW(w/1.5f);
		// shapefd.shape = &shape;
		// shapefd.density = 10.0f;
		// shapefd.friction = 0.0f;
		// shapefd.restitution = 1.1f;
		// body->CreateFixture(&shapefd);

	return rigidbody;
}


// SpriteFactory stuff
SpriteFactory::SpriteFactory(GraphicsDevice* graphics_device, ArtAssetLibrary* art_library) : ComponentFactory() {
	graphics_device_ = graphics_device;
	art_library_ = art_library;
}

SpriteFactory::~SpriteFactory() {}

Sprite* SpriteFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	Sprite* new_sprite = new Sprite(owner);
	std::string texture = node.attribute("texture").value();
	new_sprite->Initialize(graphics_device_, art_library_->Search(texture));
	return new_sprite;
}
