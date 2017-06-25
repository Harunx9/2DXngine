#include "TranslationService.h"
#include "../Services/ServiceLocator.h"
#include "SDL.h"

TranslationService::TranslationService() :Service("TranslationService")
{
    this->_binding = CREATE_BINDING(EventHandler::get_nextID(), TranslationService, onLanguageChange);
    this->_translations = translation_map();
}

TranslationService::~TranslationService()
{
}

void TranslationService::initialize()
{
    this->_parser = new SimpleCSV(';');
    this->_cfg = ServiceLocator::get<ConfigurationService>("TranslationService")
        ->get_language();
    this->_cfg->sectionUpdated += _binding;
    this->setupLanguage(this->_cfg->get_text());
}

void TranslationService::terminate()
{
    this->_cfg->sectionUpdated += _binding;
}

std::string TranslationService::getTranslation(std::string key)
{
    if (this->_translations.find(key) == this->_translations.end())
    {
        return key;
    }
    return this->_translations[key];
}

void TranslationService::onLanguageChange(EventArgs args)
{
    this->setupLanguage(this->_cfg->get_text());
}

void TranslationService::setupLanguage(std::string lang)
{
    std::string path = std::string(SDL_GetBasePath());
    path.append(this->_cfg->get_translationDirPath());
    path.append("translation.");
    path.append(lang);
    path.append(".csv");

    csv_content content = this->_parser->parseFile(path);

    if (content.empty()) return;

    for (auto& line : content)
    {
        std::string key = line[0];
        std::string value = line[1];
        this->_translations[key] = value;
    }
}
