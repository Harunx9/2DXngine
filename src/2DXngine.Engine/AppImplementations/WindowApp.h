#pragma once
#include "App.h"
#include <SDL.h>
#include "../Graphics/GraphicDevice.h"

class ConfigurationService;
class LoggerService;

class WindowApp :
    public App
{
public:
    WindowApp(GameHandler * handler,
        const char* companyName,
        const char* appName,
        const char* configPath, 
        const char* userCfgName);
    WindowApp(const WindowApp * other) = delete;
    ~WindowApp();
    virtual void initialize() override;
    virtual void run() override;
    virtual void exit() override;
private:
    void initDirsIfNotExist();
    void buildServiceContrainer();
    void initAndRegiserConfig();
    GraphicDevice* _device;
    Timer * _timer;
    ConfigurationService* _cfgService;
    LoggerService* _logger;
    const char* _configPath;
    const char* _userCfgName;
};

