#pragma once
#include "..\Services\Service.h"
#include "ConfigSection.h"
#include <map>
#include <string>
#include "../../libs/simpleini/SimpleIni.h"
#include "../Utils/Macros/PropertyMacro.h"
#include "GraphicConfig.h"
#include "AudioConfig.h"
#include "../Utils/Events/EventHandler.h"

#define BASE_CONFIG_FILE_NAME "cfg.ini"
#define USER_CONFIG_FILE_NAME "user_cfg.ini"

class ConfigurationService :
    public Service
{
public:
    ConfigurationService(const char* appName, const char* companyName);
    ~ConfigurationService();
    virtual void initialize() override;
    virtual void terminate() override;

    READONLY_PROPERTY(GraphicConfig*, graphics)
    READONLY_PROPERTY(AudioConfig*, audio)

private: 
    void onSave(EventArgs args);
    std::string getConfigFilePath(char* basePath, const char* fileName);
    Binding<EventArgs> _binding;
    inifile* _file;
    std::string _baseConfigPath;
    std::string _userConfigPath;
    const char* _appName;
    const char* _companyName;
};
