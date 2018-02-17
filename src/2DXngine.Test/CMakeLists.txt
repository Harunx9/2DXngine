set(ENGINE_TEST_SOURCE
    Assets/ShaderProgramTest.cc
    Assets/ShaderTest.cc
    Assets/TextureTest.cc

    Components/Animation/AnimationComponentTest.cc
    Components/Animation/AnimationFactoryTest.cc
    Components/Animation/ParsersTest.cc
    Components/AI/AiTreeTest.cc
    Components/ColliderComponentTest.cc
    Components/TextDataComponent.cc
    Components/SpriteSheetComponentTest.cc
    
    GameObject/GameObjectBaseFunctionsTest.cc
    GameObject/GameObjectComponentModelTest.cc
    GameObject/GameObjectGraphTest.cc
    GameObject/GameObjectLifetimeTest.cc
    GameObject/GameObjectManagerTest.cc

    Graphics/CameraUnprojectTest.cc
    Graphics/ColorFromStringTest.cc
    Graphics/RenderTargetTest.cc

    Integration_Tiled/Factory/CreateTileLayerObjectsTest.cc
    Integration_Tiled/Factory/CreateTilesetGameObjectTest.cc
    Integration_Tiled/Factory/FactoryTestFixture.h
    
    Integration_Tiled/ParserTest/ImageLayerTest.cc
    Integration_Tiled/ParserTest/MapGroupTest.cc
    Integration_Tiled/ParserTest/ParseMapTest.cc
    Integration_Tiled/ParserTest/ParseObjectGroupTest.cc
    Integration_Tiled/ParserTest/TileLayerTest.cc
    Integration_Tiled/ParserTest/TilesetTest.cc
    Integration_Tiled/ParserTest/TiledFixture.h

    Scenes/TestScene.h

    Services/ConfigurationServiceTest.cc
    Services/ContentManagerTest.cc
    Services/TranslationServiceTest.cc

    TypeSystem/TestComponents.h
    TypeSystem/TestComponents.cc
    TypeSystem/TestTypes.h
    TypeSystem/TestTypes.cc
    TypeSystem/TestTypesHierarhy.h
    TypeSystem/TestTypesHierarhy.cc
    TypeSystem/TypeIdHelperTest.cc

    Utils/BackgroundTaskTest.cc
    Utils/EventHandlingTest.cc
    Utils/EventTestData.h
    Utils/PropertyMacroTest.cc
    Utils/PropTestClass.h
    Utils/RectangleTest.cc
    Utils/ResultTest.cpp
    Utils/SimpleCsvTest.cc
    Utils/StringUtilsTest.cc
)

include_directories(
    ${GTEST_INCLUDE_DIR}
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

set (TEST_CONTENT ${PROJECT_SOURCE_DIR}/src/2DXngine.Test/Content)
set (TEST_CFG_INI ${PROJECT_SOURCE_DIR}/src/2DXngine.Test/cfg.ini)

foreach(FILE ${ENGINE_TEST_SOURCE}) 
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

add_executable(EngineTests ${ENGINE_TEST_SOURCE})

if(WIN32)
    target_link_libraries(EngineTests 
        ${GTEST_BOTH_LIBRARIES}
        Engine
        opengl32.lib
        ${GLEW_LIBRARIES}
        ${SDL2_LIBRARY}
        ${SDL2_MIXER_LIBRARIES}
        ${FREETYPE_LIBRARIES}
        ${SOIL_LIBRARY}
    )
elseif(APPLE)
    target_link_libraries(EngineTests 
        ${GTEST_BOTH_LIBRARIES}
        Engine
        ${OPENGL_LIBRARY}
        ${GLEW_LIBRARIES}
        ${SDL2_LIBRARY}
        ${SDL2_MIXER_LIBRARIES}
        ${FREETYPE_LIBRARIES}
        ${SOIL_LIBRARY}
    )
endif()

add_custom_command(TARGET EngineTests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${TEST_CONTENT}
    "${CMAKE_BINARY_DIR}/src/2DXngine.Test/Debug/Content"
)

add_custom_command(TARGET EngineTests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${TEST_CFG_INI}
    "${CMAKE_BINARY_DIR}/src/2DXngine.Test/Debug"
)

if(WIN32)
    add_custom_command(
        TARGET EngineTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        ${ALL_WIN32_DLLS} 
        "${CMAKE_BINARY_DIR}/src/2DXngine.Test/Debug"
    )
elseif(WIN64)
    add_custom_command(
        TARGET EngineTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        ${ALL_WIN64_DLLS} 
        "${CMAKE_BINARY_DIR}/src/2DXngine.Test/Debug"
    )
endif()

if(Environ STREQUAL "VS")
    add_custom_command(
        TARGET EngineTests POST_BUILD
        COMMAND EngineTests
    )
endif()