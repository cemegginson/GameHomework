#pragma once

#include <map>
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
	std::vector<std::shared_ptr<Component>> components_;
	std::map<ActorEvent, bool> actor_events_;
    Vector2 position_;
	Vector2 dimensions_;
    float32 angle_;
    bool is_circle_;
	bool is_square_;

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
