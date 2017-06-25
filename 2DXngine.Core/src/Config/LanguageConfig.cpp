#include "LanguageConfig.h"

LanguageConfig::LanguageConfig(inifile * file, std::string text, std::string translationDirPath) 
    : ConfigSection(file, ConfigurationSections::LANGUAGE),
    _text(text),
    _translationDirPath(translationDirPath)
{
}

LanguageConfig::~LanguageConfig()
{
}

LanguageConfig * LanguageConfig::loadInternal(inifile * ini)
{
    std::string text = std::string(ini->GetValue("Language", "Text", "en-us"));
    std::string translationDirPath = std::string(ini->GetValue("Language", "TransDirPath", "\\Content\\Translations\\"));
    return new LanguageConfig(ini, text, translationDirPath);
}
