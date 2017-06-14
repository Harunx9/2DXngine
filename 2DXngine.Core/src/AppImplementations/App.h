#pragma once
#include "../Utils/GameHandler.h"
#include "../Utils/Timer.h"

class App
{
public:
    App(GameHandler * handler,
        const char* companyName,
        const char* appName);
    App(const App& app) = delete;
    virtual ~App();
    virtual void initialize() = 0;
    virtual void run() = 0;
    virtual void exit() = 0;
    bool get_isRunning() const;
    bool get_isInitialized() const;
protected:
    bool _isRunning;
    bool _isInitialized;
    float _timeStep;
    bool _isFixedTimeStep;
    GameHandler * _game;
    const char* _companyName;
    const char* _appName;
};

