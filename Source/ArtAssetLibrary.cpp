#include "ArtAssetLibrary.h"

ArtAssetLibrary::ArtAssetLibrary() {

}

ArtAssetLibrary::~ArtAssetLibrary() {

}

Texture* Search(std::string key) {
    return library.at(key);
}
