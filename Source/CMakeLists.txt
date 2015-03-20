project(GameHomework1)

    add_executable(GameHomework1 Source.cpp ArtAssetLibrary.cpp Carrier.cpp
        Factory.cpp Game.cpp GraphicsDevice.cpp Infantry.cpp InputDevice.cpp
        Object.cpp pugixml.cpp Texture.cpp Timer.cpp View.cpp)


    target_link_libraries(GameHomework1 ${SDL2_LIBRARY})
    target_link_libraries(GameHomework1 SDL_image)

    install(TARGETS RUNTIME DESTINATION ${BIN_DIR})
