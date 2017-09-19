#include "Enums.h"
#include <cstring>

LoggerVerbosity mapToVerbosity(const char * name)
{
    if (std::strcmp(name, "ALL") == 0)
        return LoggerVerbosity::ALL;
    if (std::strcmp(name, "INFO") == 0)
        return LoggerVerbosity::INFO;
    if (std::strcmp(name, "WARN") == 0)
        return LoggerVerbosity::WARN;
    if (std::strcmp(name, "ERRORS") == 0)
        return LoggerVerbosity::ERRORS;
    if (std::strcmp(name, "DEBUG") == 0)
        return LoggerVerbosity::DEBUG;

    return LoggerVerbosity::NONE;
}

LoggerType mapToLoggerType(const char * name)
{
    if (std::strcmp(name, "CONSOLE") == 0)
        return LoggerType::CONSOLE;
    if (std::strcmp(name, "FILE") == 0)
        return LoggerType::FILE;

    return LoggerType::NONE;
}
