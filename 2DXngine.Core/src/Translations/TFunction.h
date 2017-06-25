#pragma once
#include "../Services/ServiceLocator.h"
#include "TranslationService.h"
#include <string>

inline std::string T(std::string key)
{
    return ServiceLocator
        ::get<TranslationService>("TranslationService")
        ->getTranslation(key);
}