#pragma once
#include "../Services/Service.h"
#include <map>
#include <string>

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
    translation_map _translations;
    const char _csvSeparator = ';';
};

