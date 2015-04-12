#pragma once

#include <string>
#include <Box2D/Box2D.h>
#include "Definitions.h"

class GamePhysics {
protected:
    GAME_FLT density;
	GAME_FLT restitution;
	GAME_FLT angularDamping;
	GAME_FLT linearDamping;
	GAME_FLT angularForce;
	GAME_FLT linearForce;
	std::string type;
	std::string shape;

public:
    GamePhysics();
    ~GamePhysics();
    void Initialize();
    
};
