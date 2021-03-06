#pragma once
#include <string>
#include "../Utils/Macros/PropertyMacro.h"
#include "../../thirdparty/simpleini/SimpleIni.h"
#include "../Utils/Events/EventHandler.h"

typedef CSimpleIniA inifile;

enum ConfigurationSections
{
    GRAPHICS,
    AUDIO,
    KEYBOARD,
    MOUSE,
    LANGUAGE,
    LOGGER
};

class ConfigSection
{
public:
    EventHandler sectionUpdated;

    ConfigSection(inifile * ini, ConfigurationSections name);
    virtual ~ConfigSection();

    template<class TSection>
    static TSection* load(inifile* ini);

    READONLY_PROPERTY(ConfigurationSections, name)
protected:
    void sectionUpdatedHandler();
    inifile * _ini;
};

template<class TSection>
inline TSection* ConfigSection::load(inifile* ini)
{
    return (TSection*) TSection::loadInternal(ini);
}
