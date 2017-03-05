#include "App.h"


App::App(GameHandler * handler) : 
    _isInitialized(false),
    _isRunning(false)
{
    _game = handler;
}

App::~App()
{
}

bool App::getIsRunning() const
{
    return this->_isRunning;
}

bool App::getIsInitialized() const
{
    return this->_isInitialized;
}