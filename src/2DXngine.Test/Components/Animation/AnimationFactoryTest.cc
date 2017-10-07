#include "gtest\gtest.h"
#include <Components\Graphics\AnimationFactory\XMLSpritesheetAnimationFactory.h>
#include <Components\Graphics\AnimationComponent.h>

TEST(AnimationFactory, animation_can_be_created_from_all_animations_in_xml_file)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet.xml");

    auto animComponent = XMLSpritesheetAnimationFactory::createFromXmlWithAllNames(path) ;

    ASSERT_TRUE(animComponent != nullptr);
}

TEST(AnimationFactory, animation_can_be_created_from_specified_animations_in_xml_file)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet.xml");
    std::vector<std::string> names;
    names.push_back("animationName2");

    auto animComponent = XMLSpritesheetAnimationFactory::createFromXmlWithDefinedNames(path, names);

    ASSERT_TRUE(animComponent != nullptr);
}

TEST(AnimationFactory, animation_component_will_be_null_if_spritesheet_not_exist)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet2.xml");

    auto animComponent = XMLSpritesheetAnimationFactory::createFromXmlWithAllNames(path);

    ASSERT_TRUE(animComponent == nullptr);
}

TEST(AnimationFactory, animation_can_be_created_from_spritesheet_with_defined_animations)
{
    AssetPath path = AssetPath::create("Content\\testspritesheet.xml");
    std::vector<AnimationDefinition> definitions;
    definitions.push_back({"run", 0, 8, 4});

    auto animComponent = XMLSpritesheetAnimationFactory::createFromXml(path, definitions);

    ASSERT_TRUE(animComponent != nullptr);
}

TEST(AnimationFactory, if_sprtesheet_not_exist_animation_will_be_null)
{
    AssetPath path = AssetPath::create("Content\\testspritesheet2.xml");
    std::vector<AnimationDefinition> definitions;
    definitions.push_back({ "run", 0, 8, 4 });

    auto animComponent = XMLSpritesheetAnimationFactory::createFromXml(path, definitions);

    ASSERT_TRUE(animComponent == nullptr);
}