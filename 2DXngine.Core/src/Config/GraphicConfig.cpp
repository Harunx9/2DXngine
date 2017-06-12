#include "GraphicConfig.h"


GraphicConfig::GraphicConfig(inifile * ini, bool isFullScreen, int windowWidth,
    int windowHeight, int openGLMinorVerion, int openGLMajorVerion, int doubleBufferToggle) :
    ConfigSection(ini, ConfigurationSections::GRAPHICS),
    _isFullScreen(isFullScreen),
    _windowWidth(windowWidth),
    _windowHeight(windowHeight),
    _openGLMinorVerion(openGLMinorVerion),
    _openGLMajorVerion(openGLMajorVerion),
    _doubleBufferToggle(doubleBufferToggle)
{
}

GraphicConfig::~GraphicConfig()
{
}

GraphicConfig * GraphicConfig::loadInternal(inifile * ini)
{
    bool isFullScreen = ini->GetBoolValue("Graphics", "FullScreen");
    int windowWidth = (int)ini->GetLongValue("Graphics", "WindowWidth", 640);
    int windowHeight = (int)ini->GetLongValue("Graphics", "WindowWidth", 360);
    int openGLMinorVerion = (int)ini->GetLongValue("Graphics", "GLMinor", 3);
    int openGLMajorVerion = (int)ini->GetLongValue("Graphics", "GLMajor", 3);
    int doubleBufferToggle = (int)ini->GetLongValue("Graphics", "DoubleBuffer", 1);

    return new GraphicConfig(ini, isFullScreen, windowWidth, windowHeight, openGLMinorVerion, openGLMajorVerion, doubleBufferToggle);
}
