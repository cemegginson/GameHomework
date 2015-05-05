#pragma once

#include <string>
#include <Box2D/Box2D.h>

#include "Component.h"
#include "Definitions.h"

// Base Rigidbody class
class Rigidbody : public Component{
protected:
	std::string type_;
	std::string shape_;
    b2World* world_;
    b2Body* body_;

    bool physics_movable;

public:
    Rigidbody(std::shared_ptr<Actor>);
    ~Rigidbody();
    void Initialize(b2World*);
    void Update(float32);
    void ExportPosition();
    void ExportAngle();
	void ImportPosition();
	void ImportAngle();
};

// Physics Circles
class RigidCircle : public Rigidbody {
protected:
    b2Shape
public:

}

// Physics Rectangles
class RigidRectangle : public Rigidbody {
protected:

public:

}
