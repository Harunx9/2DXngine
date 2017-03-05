#pragma once
#include "../Utils/GameHandler.h"
#include "../Utils/Timer.h"

class App
{
public:
    App(GameHandler * handler);
    App(const App& app) = delete;
    virtual ~App();
    virtual void initialize() = 0;
    virtual void run() = 0;
    virtual void exit() = 0;
    bool getIsRunning() const;
    bool getIsInitialized() const;
protected:
    bool _isRunning;
    bool _isInitialized;
    float _timeStep;
    bool _isFixedTimeStep;
    GameHandler * _game;
};

