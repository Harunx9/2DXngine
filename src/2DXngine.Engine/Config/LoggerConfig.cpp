#include "LoggerConfig.h"

LoggerConfig::LoggerConfig(inifile * ini, LoggerType type, LoggerVerbosity verbosity, std::string filePath) : ConfigSection(ini, ConfigurationSections::LOGGER),
    _type(type),
    _verbosity(verbosity),
    _filePath(filePath)
{
}

LoggerConfig::~LoggerConfig()
{
}

LoggerConfig * LoggerConfig::loadInternal(inifile * ini)
{
    auto verbosity = mapToVerbosity(ini->GetValue("Logger", "Verbosity"));
    auto loggerType = mapToLoggerType(ini->GetValue("Logger", "LoggerType"));
    auto filePath = std::string(ini->GetValue("Logger", "File", ""));

    return new LoggerConfig(ini, loggerType, verbosity, filePath);
}
