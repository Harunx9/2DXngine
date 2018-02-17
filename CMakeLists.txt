cmake_minimum_required(VERSION 3.8)

project(2DXngine)

message(STATUS "CMAKE ENV ${Environ}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/modules/")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W1 /MP /Gm-")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /INCREMENTAL /debug:fastlink")
    set (GTEST_MSVC_SEARCH "MD")
endif(MSVC)

if(WIN32 OR Win64)

    set(SDL2_PATH  "${PROJECT_SOURCE_DIR}/thirdparty/SDL2-2.0.5")
    set(GLM_ROOT_DIR "${PROJECT_SOURCE_DIR}/thirdparty/gllibs")
    set(SOIL_ROOT_DIR "${PROJECT_SOURCE_DIR}/thirdparty/gllibs/soil")
    set(ENV{SDL2MIXERDIR} "${PROJECT_SOURCE_DIR}/thirdparty/SDL2_mixer-2.0.1")
    set(GTEST_ROOT "${PROJECT_SOURCE_DIR}/thirdparty/googletest/googletest")

    list(APPEND CMAKE_PREFIX_PATH
        "${PROJECT_SOURCE_DIR}/thirdparty/glew-2.0.0"
        "${PROJECT_SOURCE_DIR}/thirdparty/freetype-2.3.5-1"
    )

    list(APPEND CMAKE_LIBRARY_PATH "${PROJECT_SOURCE_DIR}/thirdparty/freetype-2.3.5-1/lib/")

    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        list(APPEND CMAKE_LIBRARY_PATH
            "${PROJECT_SOURCE_DIR}/thirdparty/glew-2.0.0/lib/Release/x64")
    else()
        list(APPEND CMAKE_LIBRARY_PATH 
            "${PROJECT_SOURCE_DIR}/thirdparty/glew-2.0.0/lib/Release/Win32")
    endif()


    set(FREETYPE_DLLS
        "${PROJECT_SOURCE_DIR}/thirdparty/freetype-2.3.5-1/bin/freetype6.dll"
        "${PROJECT_SOURCE_DIR}/thirdparty/freetype-2.3.5-1/bin/zlib1.dll")

    set(SDL2_DLL_WIN32 "${PROJECT_SOURCE_DIR}/thirdparty/SDL2-2.0.5/lib/x86/SDL2.dll")
    set(SDL2_DLL_WIN64 "${PROJECT_SOURCE_DIR}/thirdparty/SDL2-2.0.5/lib/x64/SDL2.dll")

    set(GLEW_DLL_WIN32 "${PROJECT_SOURCE_DIR}/thirdparty/glew-2.0.0/bin/Release/Win32/glew32.dll")
    set(GLEW_DLL_WIN64 "${PROJECT_SOURCE_DIR}/thirdparty/glew-2.0.0/bin/Release/x64/glew32.dll")

    set(SDL2MIXER_DLL_WIN32 
        "${PROJECT_SOURCE_DIR}/thirdparty/SDL2_mixer-2.0.1/lib/x86/SDL2_mixer.dll"
        "${PROJECT_SOURCE_DIR}/thirdparty/SDL2_mixer-2.0.1/lib/x86/libogg-0.dll"
        "${PROJECT_SOURCE_DIR}/thirdparty/SDL2_mixer-2.0.1/lib/x86/smpeg2.dll")

    set(SDL2MIXER_DLL_WIN64 
        "${PROJECT_SOURCE_DIR}/thirdparty/SDL2_mixer-2.0.1/lib/x64/SDL2_mixer.dll"
        "${PROJECT_SOURCE_DIR}/thirdparty/SDL2_mixer-2.0.1/lib/x64/libogg-0.dll"
        "${PROJECT_SOURCE_DIR}/thirdparty/SDL2_mixer-2.0.1/lib/x64/smpeg2.dll")

    set(ALL_WIN32_DLLS 
        ${FREETYPE_DLLS}
        ${SDL2_DLL_WIN32}
        ${SDL2MIXER_DLL_WIN32}    
        ${GLEW_DLL_WIN32}
    )

    set(ALL_WIN64_DLLS 
        ${FREETYPE_DLLS}
        ${SDL2_DLL_WIN64}
        ${SDL2MIXER_DLL_WIN64}    
        ${GLEW_DLL_WIN64}
    )
elseif(APPLE)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    set(SDL2_PATH  "/usr/local/lib")
    set(GLM_ROOT_DIR "${PROJECT_SOURCE_DIR}/thirdparty/gllibs")
    set(SOIL_ROOT_DIR "/usr/local")
    set(ENV{SDL2MIXERDIR} "/usr/local/lib")
    set(GTEST_ROOT "${PROJECT_SOURCE_DIR}/thirdparty/googletest/googletest")
    find_package(OpenGL REQUIRED)
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(Freetype REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)
find_package(SOIL REQUIRED)
enable_testing()
find_package(GoogleTest REQUIRED)

set(SIMPLE_INI_SRC
    ${PROJECT_SOURCE_DIR}/thirdparty/simpleini/ConvertUTF.h
    ${PROJECT_SOURCE_DIR}/thirdparty/simpleini/ConvertUTF.c
    ${PROJECT_SOURCE_DIR}/thirdparty/simpleini/SimpleIni.h
)

set(PUGI_XML_SRC
    ${PROJECT_SOURCE_DIR}/thirdparty/pugixml/src/pugiconfig.hpp
    ${PROJECT_SOURCE_DIR}/thirdparty/pugixml/src/pugixml.hpp
    ${PROJECT_SOURCE_DIR}/thirdparty/pugixml/src/pugixml.cpp
)

add_subdirectory(src/2DXngine.Engine)
add_subdirectory(src/2DXngine.Main)
add_subdirectory(src/2DXngine.Test)