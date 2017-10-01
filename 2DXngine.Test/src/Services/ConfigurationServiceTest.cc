#pragma once
#include "gtest\gtest.h"
#include <Services\ServiceLocator.h>
#include <Config\ConfigurationService.h>

class ConfigurationTestFixture : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        auto cfg = new ConfigurationService("Test", "Testing", "cfg.ini", "usercfg.ini");
        cfg->baseInitialize();
        ServiceLocator::registerService<ConfigurationService>(cfg);
        ServiceLocator::initialize();
    }
};


TEST_F(ConfigurationTestFixture, graphics_section_should_be_loaded)
{
    auto svc = ServiceLocator::get<ConfigurationService>("ConfigurationService");
    
    auto graphics = svc->get_graphics();

    ASSERT_FALSE(graphics->get_isFullScreen());
    ASSERT_TRUE(graphics->get_doubleBufferToggle());
    ASSERT_EQ(graphics->get_windowHeight(), 360);
    ASSERT_EQ(graphics->get_windowWidth(), 640);
    ASSERT_EQ(graphics->get_openGLMinorVerion(), 3);
    ASSERT_EQ(graphics->get_openGLMajorVerion(), 3);
}


TEST_F(ConfigurationTestFixture, audio_section_should_be_loaded)
{
    auto svc = ServiceLocator::get<ConfigurationService>("ConfigurationService");

    auto audio = svc->get_audio();

    ASSERT_EQ(audio->get_channelsNumber(), 256);
    ASSERT_EQ(audio->get_audioVolumeFactor(), 0.5f);
    ASSERT_EQ(audio->get_musicVolumeFactor(), 0.5f);
    ASSERT_EQ(audio->get_soundVolumeFactor(), 0.5f);
}

TEST_F(ConfigurationTestFixture, language_section_should_be_loaded)
{
    auto svc = ServiceLocator::get<ConfigurationService>("ConfigurationService");

    auto language = svc->get_language();

    ASSERT_EQ(language->get_text(), "pl-PL");
    ASSERT_EQ(language->get_translationDirPath(), "\\\\Content\\\\Translations\\\\");
}