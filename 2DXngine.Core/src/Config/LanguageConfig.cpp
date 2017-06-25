#include "LanguageConfig.h"

LanguageConfig::LanguageConfig(inifile * file) : ConfigSection(file, ConfigurationSections::LANGUAGE)
{
}

LanguageConfig::~LanguageConfig()
{
}