#include "ConfigurationService.h"
#include "../Utils/File.h"
#include <SDL.h>

ConfigurationService::ConfigurationService(const char* appName, const char* companyName,
    const char* cfgName, const char* userCfgName) : Service("ConfigurationService"),
_appName(appName),
_companyName(companyName),
_cfgName(cfgName),
_userCfgName(userCfgName)
{
    this->_binding = CREATE_BINDING(EventHandler::get_nextID(), ConfigurationService, onSave);
}


ConfigurationService::~ConfigurationService()
{

}

void ConfigurationService::initialize()
{
    this->_baseConfigPath = getConfigFilePath(SDL_GetBasePath(), this->_cfgName);
    if (File::exist(std::string(this->_baseConfigPath)) == false)
        return;

#if RELEASE
    this->_userConfigPath = getConfigFilePath(SDL_GetPrefPath(this->_companyName, this->_appName), this->_userCfgName);
#else
    this->_userConfigPath = this->_baseConfigPath;
#endif

    auto prefsFilePath = File::exist(std::string(this->_userConfigPath)) ? this->_userConfigPath.c_str() : this->_baseConfigPath.c_str();
    this->_file = new inifile();
    this->_file->LoadFile(prefsFilePath);

    this->_graphics = GraphicConfig::load<GraphicConfig>(this->_file);
    this->_graphics->sectionUpdated += _binding;

    this->_audio = AudioConfig::load<AudioConfig>(this->_file);
    this->_audio->sectionUpdated += _binding;

    this->_language = LanguageConfig::load<LanguageConfig>(this->_file);
    this->_language->sectionUpdated += _binding;

    this->_logger = LoggerConfig::load<LoggerConfig>(this->_file);
}

void ConfigurationService::terminate()
{
    this->_graphics->sectionUpdated -= _binding;
    this->_audio->sectionUpdated -= _binding;
    this->_language->sectionUpdated -= _binding;

    delete _graphics;
    delete _audio;
    delete _file;
    delete _logger;
}

std::string ConfigurationService::getConfigFilePath(char * basePath, const char * fileName)
{
    std::string bPath = std::string(basePath);
    bPath.append(fileName);
    return bPath;
}

void ConfigurationService::onSave(EventArgs args)
{
    if (this->_file != nullptr)
    {
        this->_file->SaveFile(this->_userConfigPath.c_str());
    }
}
