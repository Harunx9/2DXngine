#pragma once
#include "ConfigSection.h"

class LanguageConfig : public ConfigSection
{
public:
    LanguageConfig(inifile * file);
    ~LanguageConfig();

    PROPERTY(std::string, language)
    READONLY_PROPERTY(std::string, translationDirPath)

private:
    inifile * _file;
};

