#pragma once

#include <vector>

#include "Component.h"
#include "Definitions.h"
#include "InputDevice.h"
#include "View.h"

class Actor : public std::enable_shared_from_this<Actor> {
protected:
	std::vector<std::shared_ptr<Component>> components;
    vector2 position;
    float32 angle;
    bool initialized;

public:
	Actor();
	~Actor();
	bool Initialize(GraphicsDevice*, std::string);
	void AddComponent(std::shared_ptr<Component>);

	template<class T>
	std::shared_ptr<T> GetComponent();

	void Update();
};
