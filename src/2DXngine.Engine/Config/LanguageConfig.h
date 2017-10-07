#pragma once
#include "ConfigSection.h"

class LanguageConfig : public ConfigSection
{
public:
    LanguageConfig(inifile * file, std::string text, std::string translationDirPath);
    ~LanguageConfig();

    static LanguageConfig * loadInternal(inifile* ini);

    std::string get_text() const
    {
        return this->_text;
    }

    void set_text(std::string text)
    {
        if (text.compare(this->_text) != 0)
        {
            this->_text = text;
            this->sectionUpdatedHandler();
        }
    }

    READONLY_PROPERTY(std::string, translationDirPath)

private:
    inifile * _file;
    std::string _text;
};
