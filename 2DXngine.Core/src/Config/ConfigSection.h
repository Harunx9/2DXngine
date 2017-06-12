#pragma once
#include <string>
#include "../Utils/Macros/PropertyMacro.h"
#include "../../libs/simpleini/SimpleIni.h"
#include "../Utils/Events/EventHandler.h"

typedef CSimpleIniA inifile;

enum ConfigurationSections
{
    GRAPHICS,
    AUDIO,
    KEYBOARD,
    MOUSE
};

class ConfigSection
{
public:
    EventHandler sectionUpdated;

    ConfigSection(inifile * ini, ConfigurationSections name);
    virtual ~ConfigSection();

    template<class TSection>
    static TSection load(inifile* ini);

    READONLY_PROPERTY(ConfigurationSections, name)
protected:
    void sectionUpdatedHandler();
    inifile * _ini;
};

template<class TSection>
inline TSection ConfigSection::load(inifile* ini)
{
    return TSection::loadInternal(ini);
}
