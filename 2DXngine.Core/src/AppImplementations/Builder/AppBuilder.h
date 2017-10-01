#pragma once
#include <string>
#include "../App.h"
#include "../../Utils/GameHandler.h"

enum class AppPlatform
{
    WINDOWS,
};

class AppBuilder
{
public:
    static AppBuilder* createForPlatrorm(AppPlatform platform);
    AppBuilder* withName(const char * name);
    AppBuilder* withCompanyName(const char * companyName);
    AppBuilder* withHandler(GameHandler* handler);
    AppBuilder* withConfig(const char * configPath);
    AppBuilder* withUserConfig(const char * userCfgName);
    App* build();
    void buildAndRun();
private:
    AppBuilder();
    ~AppBuilder();

    AppPlatform _platform;
    const char * _name;
    const char * _companyName;
    GameHandler* _handler;
    const char * _configPath;
    const char * _userCfgName;
};

