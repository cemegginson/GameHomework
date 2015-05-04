#pragma once

#include <string>
#include <Box2D/Box2D.h>

#include "Component.h"
#include "Definitions.h"

class Rigidbody : public Component{
protected:
	std::string type_;
	std::string shape_;
    b2World* world_;
    b2Body* body_;

    bool physics_movable;

public:
    Rigidbody();
    ~Rigidbody();
    void Initialize(b2World*);
    void Update(float32);
    void ExportPosition();
    void ExportAngle();
};
