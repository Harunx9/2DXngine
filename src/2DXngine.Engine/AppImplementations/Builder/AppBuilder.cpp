#include "AppBuilder.h"
#include "../WindowApp.h"

AppBuilder::AppBuilder():
    _userCfgName("user_cfg.ini"),
    _configPath("cfg.ini"),
    _name("game"),
    _companyName("company"),
    _platform(AppPlatform::WINDOWS),
    _handler(new EmptyGameHandler())
{
}


AppBuilder::~AppBuilder()
{
}

AppBuilder * AppBuilder::createForPlatrorm(AppPlatform platform)
{
    auto builder = new AppBuilder();
    builder->_platform = platform;
    return builder;
}

AppBuilder * AppBuilder::withName(const char * name)
{
    this->_name = name;
    return this;
}

AppBuilder * AppBuilder::withCompanyName(const char * companyName)
{
    this->_companyName = companyName;
    return this;
}

AppBuilder * AppBuilder::withHandler(GameHandler * handler)
{
    this->_handler = handler;
    return this;
}

AppBuilder * AppBuilder::withConfig(const char * configPath)
{
    this->_configPath = configPath;
    return this;
}

AppBuilder * AppBuilder::withUserConfig(const char * userCfgName)
{
    this->_userCfgName = userCfgName;
    return this;
}

App * AppBuilder::build()
{
    switch (this->_platform)
    {
    case AppPlatform::WINDOWS:
        return new WindowApp(this->_handler, this->_companyName, this->_name, this->_configPath, this->_userCfgName);
    default:
        return nullptr;
    }
}

void AppBuilder::buildAndRun()
{
    auto app = this->build();
    app->initialize();
    if (app->get_isInitialized())
    {
        app->run();
        if (app->get_isRunning() == false)
        {
            app->exit();
        }
    }
    delete app;
}
