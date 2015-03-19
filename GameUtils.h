#pragma once

#include <iostream>
#include <string>

#ifdef _WIN32
#include "SDL.h"
#else
#include <SDL.h>
#endif
namespace SDL {
void LogSDLError(std::ostream& os, const std::string& msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}
}