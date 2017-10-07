#include "LoggerService.h"
#include "../../Services/ServiceLocator.h"
#include "../../Config/ConfigurationService.h"
#include "LoggersImpl\ColorConsoleLogger.h"

LoggerService::LoggerService() : Service("LoggerService")
{
}


LoggerService::~LoggerService()
{
}

void LoggerService::initialize()
{
    auto cfgService = ServiceLocator::get<ConfigurationService>("ConfigurationService");
    this->_cfg = cfgService->get_logger();
    this->_loggerType = _cfg->get_type();
    this->_verbosityLevel = _cfg->get_verbosity();

    if (this->_cfg->get_type() == LoggerType::CONSOLE)
    {
        this->_logger = new ColorConsoleLogger(this);
    }
}

void LoggerService::terminate()
{
    delete _logger;
}

void LoggerService::info(char const * format, ...)
{
    va_list args;
    va_start(args, format);
    this->_logger->info(format, args);
    va_end(args);
}

void LoggerService::warn(char const * format, ...)
{
    va_list args;
    va_start(args, format);
    this->_logger->warn(format, args);
    va_end(args);
}

void LoggerService::error(char const * format, ...)
{
    va_list args;
    va_start(args, format);
    this->_logger->error(format, args);
    va_end(args);
}

void LoggerService::debug(char const * format, ...)
{
    va_list args;
    va_start(args, format);
    this->_logger->debug(format, args);
    va_end(args);
}
