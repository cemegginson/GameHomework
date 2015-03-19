#include "ArtAssetLibrary.h"

ArtAssetLibrary::ArtAssetLibrary() {

}

ArtAssetLibrary::~ArtAssetLibrary() {

}

Texture* ArtAssetLibrary::Search(std::string key) {
    return library.at(key);
}
