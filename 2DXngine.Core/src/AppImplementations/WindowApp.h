#pragma once
#include "App.h"
#include "App.h"
#include <SDL.h>
#include "../Graphics/GraphicDevice.h"
class WindowApp :
    public App
{
public:
    WindowApp(GameHandler * handler);
    WindowApp(const WindowApp * other) = delete;
    ~WindowApp();
    virtual void initialize() override;
    virtual void run() override;
    virtual void exit() override;
private:
    GraphicDevice* _device;
    Timer * _timer;
};

