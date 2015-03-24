cmake_minimum_required(VERSION 2.6)
project(GameHomework1)

# Use our modified FindSDL2* modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${GameHomework1_SOURCE_DIR}/cmake")
# ^ Not sure any of that stuff is useful on Windows without MinGW

# Set an output directory for our binaries
set(BIN_DIR ${CMAKE_SOURCE_DIRECTORY}/bin)

# Bump up warning levels appropriately for clang, gcc & msvc
# Also set debug/optimization flags depending on the build type. IDE users choose this when
# selecting the build mode in their IDE
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()


# Platform specific handling for required libraries
# if (WIN32)
# 	include_directories("./ThirdParty/SDL2-2.0.3/include")
# 	include_directories("./ThirdParty/SDL2_image-2.0.0/include")
# 	link_directories("./ThirdParty/SDL2-2.0.3/lib/x64/" "./ThirdParty/SDL2_image-2.0.0/lib/x64/")
#   add_library(SDL2 STATIC "./ThirdParty/SDL2-2.0.3/lib/x64/SDL2.lib")
# 	add_library(SDL2/SDL_image STATIC "./ThirdParty/SDL2_image-2.0.0/lib/x64/SDL2_image.lib")
# 	set_target_properties(SDL2 SDL2/SDL_image PROPERTIES LINKER_LANGUAGE C)
# elseif(UNIX)
#
# endif()

if(WIN32)
	set(SDL2_LIBRARY_TEMP "${CMAKE_SOURCE_DIRECTORY}/ThirdParty/SDL2-2.0.3/include")
	set(SDL2MAIN_LIBRARY "${CMAKE_SOURCE_DIRECTORY}/ThirdParty/SDL2-2.0.3/include")
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Include directories with relevant items
include_directories(Source)
add_subdirectory(Source)
