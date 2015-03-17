#include "Game.h"
#include "pugixml.hpp"
#include <iostream>

Game::Game() {
    gLibrary = nullptr;
    aLibrary = nullptr;
    gDevice = nullptr;
    iDevice = nullptr;
    timer;
    fps;
    gameTime;
    view = nullptr;
    vector<Object*> objects;
}

Game::~Game() {
    delete gLibrary;
    delete aLibrary;
    delete gDevice;
    delete iDevice;
    delete view;
}

bool Game::Initialize(GraphicsDevice* graphics, InputDevice* input,
    GAME_INT framerate) {
    gDevice = graphics;
    iDevice = input;
    fps = framerate;
}

void Game::Reset() {
    delete view;
    for(iterator iter = objects.begin(); iter <= objects.end(); iter++) {
        delete objects[iter];
    }
    objects.erase(objects.begin(), objects.end());
}

bool Game::LoadLevel(string file) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(file);
    if(result) {
        pugi::xml_node Level = doc.child("Level");
        for(pugi::xml_node child : Level.children("GameAsset")) {

        }
    }
}

void Game::Run() {

}

void Game::Update() {

}

void Game::Draw() {

}
