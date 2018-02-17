
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

set (CONTENT ${PROJECT_SOURCE_DIR}/src/2DXngine.Main/Content)
set (CFG_INI ${PROJECT_SOURCE_DIR}/src/2DXngine.Main/cfg.ini)

foreach(FILE ${ENGINE_MAIN_SOURCE}) 
    get_filename_component(ABSOLUTE_PATH "${FILE}" ABSOLUTE)
    get_filename_component(PARENT_DIR "${ABSOLUTE_PATH}" DIRECTORY)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")

    string(REPLACE "/" "\\" GROUP "${GROUP}")
    if ("${FILE}" MATCHES ".*\\.cpp")
        set(GROUP "${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
        set(GROUP "${GROUP}")
    endif()
        
    source_group("${GROUP}" FILES "${FILE}")
endforeach()

add_executable(2DXngine ${ENGINE_MAIN_SOURCE})

if(WIN32)
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
elseif(APPLE)
    target_link_libraries(
        2DXngine
        Engine
        ${OPENGL_LIBRARY}
        ${GLEW_LIBRARIES}
        ${SDL2_LIBRARY}
        ${SDL2_MIXER_LIBRARIES}
        ${FREETYPE_LIBRARIES}
        ${SOIL_LIBRARY}
    )
endif()

add_custom_command(TARGET 2DXngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CONTENT}
    "${CMAKE_BINARY_DIR}/src/2DXngine.Main/Debug/Content"
)

add_custom_command(TARGET 2DXngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CFG_INI}
    "${CMAKE_BINARY_DIR}/src/2DXngine.Main/Debug"
)

if(WIN32)
    add_custom_command(
        TARGET 2DXngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        ${ALL_WIN32_DLLS} 
        "${CMAKE_BINARY_DIR}/src/2DXngine.Main/Debug"
    )
elseif(WIN64)
    add_custom_command(
        TARGET 2DXngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        ${ALL_WIN64_DLLS} 
        "${CMAKE_BINARY_DIR}/src/2DXngine.Main/Debug"
    )
endif()