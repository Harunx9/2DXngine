#pragma once
#include "..\Services\Service.h"
#include <map>
#include <string>



class ConfigurationService :
    public Service
{
public:
    ConfigurationService();
    ~ConfigurationService();
    virtual void initialize() override;
    virtual void terminate() override;
};

