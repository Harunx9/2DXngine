#pragma once
#include "../Macros/PropertyMacro.h"
enum class LoggerVerbosity
{
    NONE = 0,
    INFO = 1,
    WARN = 2,
    ERRORS = 4,
    DEBUG = 5,
    ALL = INFO | WARN | ERRORS | DEBUG
};

LoggerVerbosity mapToVerbosity(const char * name);

enum class LoggerType
{
    NONE = 0,
    CONSOLE = 1,
    FILE = 2
};

LoggerType mapToLoggerType(const char * name);

class LoggerSettingsHolder
{
public:
    LoggerVerbosity get_verbosityLevel() const
    {
        return this->_verbosityLevel;
    }
    
    LoggerType  get_loggerType() const
    {
        return this->_loggerType;
    }

protected:
    LoggerVerbosity _verbosityLevel;
    LoggerType _loggerType;
};
