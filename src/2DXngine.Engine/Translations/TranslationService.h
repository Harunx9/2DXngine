#pragma once
#include "../Services/Service.h"
#include <map>
#include <string>
#include "../Utils/SimpleCSV.h"
#include "../Config/LanguageConfig.h"
#include "../Config/ConfigurationService.h"

typedef std::map<std::string, std::string> translation_map;

class TranslationService: public Service
{
public:
    TranslationService();
    ~TranslationService();

    virtual void initialize() override;
    virtual void terminate() override;

    std::string getTranslation(std::string key);
    
private:
    void onLanguageChange(EventArgs args);
    void setupLanguage(std::string lang);
    Binding<EventArgs> _binding;
    translation_map _translations;
    SimpleCSV * _parser;
    LanguageConfig * _cfg;
};

