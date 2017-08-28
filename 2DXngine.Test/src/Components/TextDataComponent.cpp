#include "gtest\gtest.h"
#include <Components\Data\TextComponent.h>
#include <Services\ServiceLocator.h>
#include <ContentManagement\ContentManagerService.h>
#include <Components\Data\FontComponent.h>
#include <ContentManagement\DefaultAssets\TTFont.h>


TEST(TextComponentTest, component_should_return_desired_text)
{
    auto component = new TextComponent("This is only test");

    auto result = component->get_text();

    ASSERT_EQ("This is only test", result);
}

class FontComponentTestFixute : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        ServiceLocator::registerService<ContentManagerService>(new ContentManagerService());
        ServiceLocator::initialize();
    }
};


TEST_F(FontComponentTestFixute, component_should_load_desired_font)
{
    auto path = AssetPath::create("Content\\babyblocks.ttf");
    auto component = new FontComponent(path);

    component->baseInitialize();

    ASSERT_TRUE(component->get_font() != nullptr);
}