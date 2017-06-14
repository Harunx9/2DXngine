#include "App.h"


App::App(GameHandler * handler, const char* companyName, const char* appName) :
    _isInitialized(false),
    _isRunning(false),
    _appName(appName),
    _companyName(companyName)
{
    _game = handler;
}

App::~App()
{
}

bool App::get_isRunning() const
{
    return this->_isRunning;
}

bool App::get_isInitialized() const
{
    return this->_isInitialized;
}