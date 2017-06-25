#include "TranslationService.h"

TranslationService::TranslationService() :Service("TranslationService")
{
}

TranslationService::~TranslationService()
{
}

void TranslationService::initialize()
{

}

void TranslationService::terminate()
{
}

std::string TranslationService::getTranslation(std::string key)
{
    if (this->_translations.find(key) == this->_translations.end())
    {
        return key;
    }
    return this->_translations[key];
}
