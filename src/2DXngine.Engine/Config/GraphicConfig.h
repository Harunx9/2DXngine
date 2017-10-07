#pragma once
#include "ConfigSection.h"
#include "../Utils/Macros/PropertyMacro.h"

class GraphicConfig : public ConfigSection
{
public:
    GraphicConfig(
        inifile * ini,
        bool isFullScreen,
        int windowWidth,
        int windowHeight,
        int openGLMinorVerion,
        int openGLMajorVerion,
        int doubleBufferToggle);
    ~GraphicConfig();

    static GraphicConfig * loadInternal(inifile* ini);

    inline bool get_isFullScreen()const
    {
        return this->_isFullScreen;
    }

    inline int get_windowWidth()const
    {
        return this->_windowWidth;
    }

    inline int get_windowHeight()const
    {
        return this->_windowHeight;
    }

    inline int get_openGLMinorVerion()const
    {
        return this->_openGLMinorVerion;
    }

    inline int get_openGLMajorVerion()const
    {
        return this->_openGLMajorVerion;
    }

    inline int get_doubleBufferToggle()const
    {
        return this->_doubleBufferToggle;
    }

    inline void set_isFullScreen(bool isFullScreen)
    {
        if (this->_isFullScreen != isFullScreen)
        {
            this->_isFullScreen = isFullScreen;
            this->_ini->SetBoolValue("Graphics", "FullScreen", this->_isFullScreen);
            this->sectionUpdatedHandler();
        }
    }

    inline void set_windowWidth(int windowWidth)
    {
        if (this->_windowWidth != windowWidth)
        {
            this->_windowWidth = windowWidth;
            this->_ini->SetLongValue("Graphics", "WindowWidth", (long)this->_windowWidth);
            this->sectionUpdatedHandler();
        }
    }

    inline void set_windowHeight(int windowHeight)
    {
        if (this->_windowHeight != windowHeight)
        {
            this->_windowHeight = windowHeight;
            this->_ini->SetLongValue("Graphics", "WindowHeight", (long)this->_windowHeight);
            this->sectionUpdatedHandler();
        }
    }

private:
    bool _isFullScreen;
    int _windowWidth;
    int _windowHeight;
    int _openGLMinorVerion;
    int _openGLMajorVerion;
    int _doubleBufferToggle;
};

