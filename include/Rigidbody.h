#pragma once

#include <string>
#include <Box2D/Box2D.h>

#include "Component.h"
#include "Definitions.h"

class Rigidbody : Component{
protected:
    float32 density;
	float32 restitution;
	float32 angularDamping;
	float32 linearDamping;
	float32 angularForce;
	float32 linearForce;
	std::string type;
	std::string shape;

public:
    Rigidbody();
    ~Rigidbody();
    void Initialize();
    void Update(float32);
};
