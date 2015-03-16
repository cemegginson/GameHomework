#include "Game.h"
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

}

void Game::Run() {

}

void Game::Update() {

}

void Game::Draw() {

}
