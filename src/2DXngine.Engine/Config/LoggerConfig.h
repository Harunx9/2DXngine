#pragma once
#include "ConfigSection.h"
#include "../Utils/Logger/Enums.h"
#include "../Utils/Macros/PropertyMacro.h"

class LoggerConfig : public ConfigSection
{
public:
    LoggerConfig(inifile* ini, LoggerType type, LoggerVerbosity verbosity, std::string filePath);
    ~LoggerConfig();

    static LoggerConfig * loadInternal(inifile* ini);

    READONLY_PROPERTY(LoggerType, type)
    READONLY_PROPERTY(LoggerVerbosity, verbosity)
    READONLY_PROPERTY(std::string, filePath)
};

