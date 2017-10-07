#pragma once
#include "Logger.h"

#if WIN32
    #include <Windows.h>
#endif // WIN32


class ColorConsoleLogger : public Logger
{
public:
    ColorConsoleLogger(const LoggerSettingsHolder* settings);
    ~ColorConsoleLogger();

    virtual void info(char const * format, va_list args) override;
    virtual void warn(char const * format, va_list args) override;
    virtual void error(char const * format, va_list args) override;
    virtual void debug(char const * format, va_list args) override;
private:
#if WIN32
    HANDLE _consoleHandle;
#endif
};

