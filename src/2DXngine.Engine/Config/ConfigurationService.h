#pragma once
#include "../Services/Service.h"
#include "ConfigSection.h"
#include <map>
#include <string>
#include "../simpleini/SimpleIni.h"
#include "../Utils/Macros/PropertyMacro.h"
#include "GraphicConfig.h"
#include "AudioConfig.h"
#include "LoggerConfig.h"
#include "LanguageConfig.h"
#include "../Utils/Events/EventHandler.h"

class ConfigurationService :
    public Service
{
public:
    ConfigurationService(const char* appName, const char* companyName, const char* cfgName, const char* userCfgName);
    ~ConfigurationService();
    virtual void initialize() override;
    virtual void terminate() override;

    READONLY_PROPERTY(GraphicConfig*, graphics)
    READONLY_PROPERTY(AudioConfig*, audio)
    READONLY_PROPERTY(LanguageConfig*, language)
    READONLY_PROPERTY(LoggerConfig*, logger)
private: 
    void onSave(EventArgs args);
    std::string getConfigFilePath(char* basePath, const char* fileName);
    Binding<EventArgs> _binding;
    inifile* _file;
    std::string _baseConfigPath;
    std::string _userConfigPath;
    const char* _appName;
    const char* _companyName;
    const char* _cfgName;
    const char* _userCfgName;
};
