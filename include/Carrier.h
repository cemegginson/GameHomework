#pragma once

#include <string>

#include "Definitions.h"
#include "Component.h"

class Carrier : public Component {
protected:
	// Vector2 center;
	// float32 rotation;
	// int radius;
	// int w, h;

public:
	Carrier(std::shared_ptr<Actor>);
	~Carrier();
	void Update(float32);
	void Initialize();
};
