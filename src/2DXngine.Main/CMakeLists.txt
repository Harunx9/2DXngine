
set(ENGINE_MAIN_SOURCE

    main.cpp

    TestImplementation/DefinedTypes.h
    TestImplementation/DeclaredTypes.cpp
    TestImplementation/DotTestController.h
    TestImplementation/DotTestController.cpp
    TestImplementation/SceneTest.h
    TestImplementation/SceneTest.cpp
    TestImplementation/TestGameHandler.h
    TestImplementation/TestGameHandler.cpp
    TestImplementation/TestGameHandler.h
    TestImplementation/TestGameHandler.cpp
    TestImplementation/TestGameHandlerWithScenes.h
    TestImplementation/TestGameHandlerWithScenes.cpp
    TestImplementation/TestMouseCoordsComponent.h
    TestImplementation/TestMouseCoordsComponent.cpp
    TestImplementation/TestTiledScene.h
    TestImplementation/TestTiledScene.cpp
)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/2DXngine.Engine
    ${GLM_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR}
    ${SDL2_MIXER_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS} 
    ${FREETYPE_INCLUDE_DIRS}
    ${SOIL_INCLUDE_PATH}
    ${SIMPLE_INI_SRC}
    ${PUGI_XML_SRC}
)

add_executable(2DXngine ${ENGINE_MAIN_SOURCE})

target_link_libraries(
    2DXngine
    Engine
    opengl32.lib
    ${GLEW_LIBRARIES}
    ${SDL2_LIBRARY}
    ${SDL2_MIXER_LIBRARIES}
    ${FREETYPE_LIBRARIES}
    ${SOIL_LIBRARY}
)

if(WIN32)
    add_custom_command(
        TARGET 2DXngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        ${ALL_WIN32_DLLS} 
        "${CMAKE_BINARY_DIR}/src/2DXngine.Main/Debug"
    )
else()
    add_custom_command(
        TARGET 2DXngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        ${ALL_WIN64_DLLS} 
        "${CMAKE_BINARY_DIR}/src/2DXngine.Main/Debug"
    )
endif()