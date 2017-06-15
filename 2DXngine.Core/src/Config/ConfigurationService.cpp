#include "ConfigurationService.h"
#include "../Utils/File.h"
#include <SDL.h>

ConfigurationService::ConfigurationService(const char* appName, const char* companyName) : Service("ConfigurationService"),
_appName(appName),
_companyName(companyName)
{
    this->_binding = CREATE_BINDING(EventHandler::get_nextID(), ConfigurationService, onSave);
}


ConfigurationService::~ConfigurationService()
{

}

void ConfigurationService::initialize()
{
    this->_baseConfigPath = getConfigFilePath(SDL_GetBasePath(), BASE_CONFIG_FILE_NAME);
    if (File::exist(std::string(this->_baseConfigPath)) == false)
        return;

#if RELEASE
    this->_userConfigPath = getConfigFilePath(SDL_GetPrefPath(this->_companyName, this->_appName), USER_CONFIG_FILE_NAME);
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
}

void ConfigurationService::terminate()
{
    this->_graphics->sectionUpdated -= _binding;
    this->_audio->sectionUpdated -= _binding;
    delete _graphics;
    delete _audio;
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
