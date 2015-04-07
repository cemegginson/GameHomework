#include "PhysicsAssetLibrary.h"

PhysicsAssetLibrary::PhysicsAssetLibrary() {

}

PhysicsAssetLibrary::~PhysicsAssetLibrary() {

}

GamePhysics* PhysicsAssetLibrary::Search(std::string name) {
    return library.at(name);
}

void PhysicsAssetLibrary::Insert(std::string name, GamePhysics* physob) {
    library.insert(pair<std::string, GamePhysics*>(name, physob));
}

void PhysicsAssetLibrary::Initialize() {
    // Player physics object
    GamePhysics* player = new GamePhysics();
    player.Initialize();
    library.Insert("Player", player);

    // Infantry physics object
    GamePhysics* infantry = new GamePhysics();
    infantry..Initialize();
    library.Insert("Infantry", infantry);

    // Rock physics object
    GamePhysics* rock = new GamePhysics();
    rock..Initialize();
    library.Insert("Rock", rock);

    // Carrier physics object
    GamePhysics* carrier = new GamePhysics();
    carrier..Initialize();
    library.Insert("Carrier", carrier);

}
