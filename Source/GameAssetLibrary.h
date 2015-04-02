#pragma once

#include <iostream>
#include <map>
#include <string>
#include "Factory.h"

class GameAssetLibrary {
protected:
	std::map<std::string, ObjectFactory*> library;

public:
	GameAssetLibrary() {}
	~GameAssetLibrary() {}

	void AddFactory(std::string name, ObjectFactory* factory) {
		library.insert(std::pair<std::string, ObjectFactory*>(name, factory));
		return;
	}

	ObjectFactory* Search(std::string obj) {
		return library.at(obj);
	}
};
