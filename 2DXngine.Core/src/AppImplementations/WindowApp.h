#pragma once
#include "App.h"
#include "App.h"
#include <SDL.h>
#include "../Graphics/GraphicDevice.h"
class ConfigurationService;

class WindowApp :
    public App
{
public:
    WindowApp(GameHandler * handler,
        const char* companyName,
        const char* appName);
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
};

