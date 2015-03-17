#pragma once

#include <iostream>

#ifdef _WIN32
#include "SDL.h"
#else
#include <SDL.h>
#endif

void LogSDLError(std::ostream &os, const std::string& msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
}
