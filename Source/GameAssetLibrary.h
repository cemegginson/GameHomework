#pragma once

class GameAssetLibrary {
      protected:
	map<std::string, ObjectFactory*> library;

      public:
	GameAssetLibrary();
	~GameAssetLibrary();
	Object* Search(std::string obj);
}
