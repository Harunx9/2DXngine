#pragma once
#include "../../Services/Service.h"
#include "Enums.h"
#include "../../Config/LoggerConfig.h"
#include "LoggersImpl/Logger.h"
class LoggerService : public Service,
    public LoggerSettingsHolder
{
public:
    LoggerService();
    ~LoggerService();

    virtual void initialize() override;
    virtual void terminate() override;

    void info(char const * format, ...);
    void warn(char const * format, ...);
    void error(char const * format, ...);
    void debug(char const * format, ...);

private:
    LoggerConfig* _cfg;
    Logger* _logger;
};

