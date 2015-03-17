#pragma once

#include <iostream>

class GameAssetLibrary {
protected:
	map<std::string, ObjectFactory*> library;

public:
	GameAssetLibrary();
	~GameAssetLibrary() {
        delete library;
    }

    void AddFactory(std::string name, ObjectFactory* factory) {
        library.insert(std::pair<std::string, ObjectFactory*> (name,factory));
        return;
    }

	ObjectFactory* Search(std::string obj){ // Spec was jacked
        return library[obj];
    }
}
