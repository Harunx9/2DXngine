#include "gtest/gtest.h"
#include <Components/Graphics/AnimationFactory/XMLSpritesheetAnimationFactory.h>

TEST(AnimationParser, all_animations_can_be_parsed_from_xml_file)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet.xml");

    auto result = XMLAnimationSpritesheetParser::load(path);

    ASSERT_FALSE(result.empty());
    ASSERT_EQ("animationName1", result["animationName1"]->get_name());
    ASSERT_EQ("animationName2", result["animationName2"]->get_name());
    ASSERT_EQ(2, result.size());
}

TEST(AnimationParser, defined_animations_can_be_parsed_from_xml_file)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet.xml");
    std::vector<std::string> names;
    names.push_back("animationName2");
    auto result = XMLAnimationSpritesheetParser::loadWithSpecifiedNames(path, names);

    ASSERT_FALSE(result.empty());
    ASSERT_EQ("animationName2", result["animationName2"]->get_name());
    ASSERT_EQ(1, result.size());
}

TEST(SpritesheetParser, spritesheet_can_be_parsed_as_item_collection)
{
    AssetPath path = AssetPath::create("Content\\testspritesheet.xml");
    auto result = XMLSpritesheetParser::load(path);

    ASSERT_FALSE(result.empty());
    ASSERT_EQ(8, result.size());
}

TEST(AnimationParser, if_file_dont_exist_empty_animation_will_be_returnted)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet1.xml");

    auto result = XMLAnimationSpritesheetParser::load(path);

    ASSERT_TRUE(result.empty());
}

TEST(AnimationParser, if_file_dont_exist_empty_animation_will_be_returnted_for_specified_names)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet1.xml");
    std::vector<std::string> names;
    names.push_back("animationName2");

    auto result = XMLAnimationSpritesheetParser::loadWithSpecifiedNames(path, names);

    ASSERT_TRUE(result.empty());
}

TEST(SpritesheetParser, if_file_dont_exist_empty_spritesheet_will_be_returnted)
{
    AssetPath path = AssetPath::create("Content\\testspritesheet1.xml");
    auto result = XMLSpritesheetParser::load(path);

    ASSERT_TRUE(result.empty());
}