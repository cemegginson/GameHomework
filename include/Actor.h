#pragma once

#include <memory>
#include <vector>

#include "Component.h"
#include "Definitions.h"
#include "GraphicsDevice.h"
#include "InputDevice.h"
#include "View.h"

class Component;
class GraphicsDevice;

class Actor : public std::enable_shared_from_this<Actor> {
protected:
	std::vector<std::shared_ptr<Component>> components;
    Vector2 position;
	Vector2 dimensions;
    float32 angle;
    bool is_circle;
	bool is_square;

public:
	Actor();
	~Actor();
	bool Initialize(GraphicsDevice*, std::string);
	void AddComponent(std::shared_ptr<Component>);

	template<class T>
	std::shared_ptr<T> GetComponent();

	void Update(float32);

    Vector2 GetPosition();
    void SetPosition(Vector2);

    float32 GetAngle();
    void SetAngle(float32);
};
