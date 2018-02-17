#pragma once
#include "gtest/gtest.h"
#include <Services/ServiceLocator.h>
#include <Translations/TranslationService.h>
#include <Translations/TFunction.h>
#include <Config/ConfigurationService.h>

class TranslationsTestFixture : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        auto cfg = new ConfigurationService("Test", "Testing", "cfg.ini", "usercfg.ini");
        cfg->baseInitialize();
        ServiceLocator::registerService<ConfigurationService>(cfg);
        ServiceLocator::registerService<TranslationService>(new TranslationService());
        ServiceLocator::initialize();
    }
};

TEST_F(TranslationsTestFixture, proper_translations_should_be_find_from_config)
{
    auto svc = ServiceLocator::get<TranslationService>("TranslationService");

    auto result1 = svc->getTranslation("Hello");
    auto result2 = svc->getTranslation("Coin");

    ASSERT_EQ("Witaj", result1);
    ASSERT_EQ("Moneta", result2);
}

TEST_F(TranslationsTestFixture, key_should_be_returned_if_not_siutable_translations_exists)
{
    auto svc = ServiceLocator::get<TranslationService>("TranslationService");

    auto result = svc->getTranslation("Button");

    ASSERT_EQ("Button", result);
}

TEST_F(TranslationsTestFixture, T_function_should_return_proper_translation_if_it_exist_in_file)
{
    auto result = T("Hello");

    ASSERT_EQ("Witaj", result);
}

TEST_F(TranslationsTestFixture, T_function_should_return_key_if_it_not_exist_in_file)
{
    auto result = T("Button");

    ASSERT_EQ("Button", result);
}