#include "ConfigSection.h"

ConfigSection::ConfigSection(inifile * ini, ConfigurationSections name):
    _ini(ini),
    _name(name)
{
}

ConfigSection::~ConfigSection()
{
}


void ConfigSection::sectionUpdatedHandler()
{
    auto handler = this->sectionUpdated;
    if (handler.isUsed())
    {
        handler.invoke(EventArgs());
    }
}