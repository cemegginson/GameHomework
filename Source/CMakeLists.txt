project(GameHomework1)

    set(SRC_FILES Source.cpp ArtAssetLibrary.cpp Carrier.cpp
        Factory.cpp Game.cpp GraphicsDevice.cpp Infantry.cpp InputDevice.cpp
        Object.cpp pugixml.cpp Texture.cpp Timer.cpp View.cpp)

    add_executable(gamebin ${SRC_FILES})

    target_include_directories(GameHomework1 ${SDL_INCLUDE_DIRS} "${CMAKE_SOURCE_DIRECTORY}/Source")

    target_link_libraries(GameHomework1 ${SDL2_LIBRARIES})
    target_link_libraries(GameHomework1 SDL_image)

    install(TARGETS RUNTIME DESTINATION ${BIN_DIR})
