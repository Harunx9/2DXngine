#include "ColorConsoleLogger.h"
#include <iostream>
#include <ctime>
#include <stdio.h>

ColorConsoleLogger::ColorConsoleLogger(const LoggerSettingsHolder* settings) :
    Logger(settings)
{
#if WIN32
    this->_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
}


ColorConsoleLogger::~ColorConsoleLogger()
{
}

void ColorConsoleLogger::info(char const * format, va_list args)
{
    if (this->isVerbositySet(LoggerVerbosity::INFO) == false)
        return;

    auto timeResult = std::time(nullptr);
    char formatedDate[64];
    strftime(formatedDate, sizeof(formatedDate), "%x %X", localtime(&timeResult));

#if WIN32
    SetConsoleTextAttribute(this->_consoleHandle, FOREGROUND_BLUE | FOREGROUND_RED| FOREGROUND_GREEN);
    char messageBuffer[64];
    std::vsnprintf(messageBuffer, sizeof(messageBuffer), format, args);
    std::cout << "[" << formatedDate << "]" << "[Information] " << messageBuffer << std::endl;
#endif
}

void ColorConsoleLogger::warn(char const * format, va_list args)
{
    if (this->isVerbositySet(LoggerVerbosity::WARN) == false)
        return;

    auto timeResult = std::time(nullptr);
    char formatedDate[64];
    strftime(formatedDate, sizeof(formatedDate), "%x %X", localtime(&timeResult));

#if WIN32
    SetConsoleTextAttribute(this->_consoleHandle, FOREGROUND_BLUE | FOREGROUND_RED);
    char messageBuffer[64];
    std::vsnprintf(messageBuffer, sizeof(messageBuffer), format, args);
    std::cout << "[" << formatedDate << "]" << "[Warning] " << messageBuffer << std::endl;
#endif
}

void ColorConsoleLogger::error(char const * format, va_list args)
{
    if (this->isVerbositySet(LoggerVerbosity::ERRORS) == false)
        return;

    auto timeResult = std::time(nullptr);
    char formatedDate[64];
    strftime(formatedDate, sizeof(formatedDate), "%x %X", localtime(&timeResult));

#if WIN32
    SetConsoleTextAttribute(this->_consoleHandle, FOREGROUND_RED);
    char messageBuffer[64];
    std::vsnprintf(messageBuffer, sizeof(messageBuffer), format, args);
    std::cout << "[" << formatedDate << "]" << "[Error] " << messageBuffer << std::endl;
#endif
}

void ColorConsoleLogger::debug(char const * format, va_list args)
{
    if (this->isVerbositySet(LoggerVerbosity::DEBUG) == false)
        return;

    auto timeResult = std::time(nullptr);
    char formatedDate[64];
    strftime(formatedDate, sizeof(formatedDate), "%x %X", localtime(&timeResult));

#if WIN32
    SetConsoleTextAttribute(this->_consoleHandle, FOREGROUND_BLUE| FOREGROUND_INTENSITY );
    char messageBuffer[64];
    std::vsnprintf(messageBuffer, sizeof(messageBuffer), format, args);
    std::cout << "[" << formatedDate << "]" << "[Debug] " << messageBuffer << std::endl;
#endif
}
