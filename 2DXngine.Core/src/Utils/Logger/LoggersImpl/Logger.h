#pragma once
#include <cstdarg>
#include "../Enums.h"

class Logger
{
public:
    Logger(const LoggerSettingsHolder* settings) : _settings(settings) {};
    virtual ~Logger() {};

    virtual void info(char const * format, va_list args) = 0;
    virtual void warn(char const * format, va_list args) = 0;
    virtual void error(char const * format, va_list args) = 0;
    virtual void debug(char const * format, va_list args) = 0;
protected:
    const LoggerSettingsHolder* _settings;
    bool isVerbositySet(const LoggerVerbosity level) const
    {
        return this->_settings->get_verbosityLevel() == LoggerVerbosity::ALL ||
            this->_settings->get_verbosityLevel() == level;
    }
};

