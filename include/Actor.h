#pragma once

#include <map>
#include <memory>
#include <vector>

#include "Component.h"
#include "Definitions.h"
#include "InputDevice.h"
#include "View.h"

class Component;
class GraphicsDevice;

class Actor : public std::enable_shared_from_this<Actor> {
protected:
	std::string name_;
    Vector2 position_;
	Vector2 dimensions_;
    float32 angle_;
    bool is_circle_;
	bool is_square_;
	std::vector<Component*> components_;
	std::map<ActorEvent, bool> actor_events_;

public:
	Actor();
	~Actor();
	void Initialize(std::string, Vector2, uint32);
	void AddComponent(Component*);

	void Update(float32);

    Vector2 GetPosition();
    void SetPosition(Vector2);

    float32 GetAngle();
    void SetAngle(float32);

	bool CheckEvent(ActorEvent);
	void SetEvent(ActorEvent);
	void ResetEvents();
};
