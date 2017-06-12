#pragma once
#include "..\Services\Service.h"
#include "ConfigSection.h"
#include <map>
#include <string>
#include "../../libs/simpleini/SimpleIni.h"

#define CONFIG_FILE_NAME "cfg.ini"

typedef std::map<ConfigurationSections, ConfigSection*> configurtaion;

class ConfigurationService :
    public Service
{
public:
    ConfigurationService();
    ~ConfigurationService();
    virtual void initialize() override;
    virtual void terminate() override;

    template<class TSection>
    TSection* get_section(ConfigurationSections name);
private:
    configurtaion _cfg;
};

template<class TSection>
inline TSection * ConfigurationService::get_section(ConfigurationSections name)
{
    auto pair = this->_cfg.find(name);
    if (pair == this->_cfg.end())
        return nullptr;

    return (TSection *) pair[name];
}
