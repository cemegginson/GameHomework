project(GameHomework1)

set(TARGET_NAME GameHomework1)

set(SRC_FILES Source.cpp ArtAssetLibrary.cpp Carrier.cpp
    Factory.cpp Game.cpp GraphicsDevice.cpp Infantry.cpp InputDevice.cpp
    Object.cpp pugixml.cpp Texture.cpp Timer.cpp View.cpp)

add_executable(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    "${CMAKE_SOURCE_DIR}/Source")

target_link_libraries(${TARGET_NAME} ${SDL2_LIBRARY})
target_link_libraries(${TARGET_NAME} ${SDL2_IMAGE_LIBRARY})

install(TARGETS ${TARGET_NAME}
    RUNTIME DESTINATION ${BIN_DIR})
