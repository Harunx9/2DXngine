#include "gtest\gtest.h"
#include <Components\Graphics\SpriteSheetComponent.h>
#include <Components\Graphics\SpritesheetFactory\XMLSpritesheetParserFactory.h>
#include <ContentManagement\AssetPath.h>

TEST(SpriteSheetComponentTest, spritesheet_should_be_parsed_properly)
{
    AssetPath path = AssetPath::create("Content\\testspritesheet.xml");

    auto result = XMLSpritesheetParserFactory::create(path);

    ASSERT_EQ(8, result->get_sheetSize());
}

TEST(SpriteSheetComponentTest, spritesheet_first_item_should_be_parsed_properly)
{
    AssetPath path = AssetPath::create("Content\\testspritesheet.xml");
    auto component = XMLSpritesheetParserFactory::create(path);

    auto result = component->get_spriteRect("anim_1");

    ASSERT_EQ(0, result.get_x());
    ASSERT_EQ(0, result.get_y());
    ASSERT_EQ(50, result.get_width());
    ASSERT_EQ(50, result.get_height());
}

TEST(SpriteSheetComponentTest, spritesheet_second_item_should_be_parsed_properly)
{
    AssetPath path = AssetPath::create("Content\\testspritesheet.xml");
    auto component = XMLSpritesheetParserFactory::create(path);

    auto result = component->get_spriteRect("anim_2");

    ASSERT_EQ(50, result.get_x());
    ASSERT_EQ(0, result.get_y());
    ASSERT_EQ(50, result.get_width());
    ASSERT_EQ(50, result.get_height());
}

TEST(SpriteSheetComponentTest, spritesheet_third_item_should_be_parsed_properly)
{
    AssetPath path = AssetPath::create("Content\\testspritesheet.xml");
    auto component = XMLSpritesheetParserFactory::create(path);

    auto result = component->get_spriteRect("anim_3");

    ASSERT_EQ(50, result.get_x());
    ASSERT_EQ(50, result.get_y());
    ASSERT_EQ(50, result.get_width());
    ASSERT_EQ(50, result.get_height());
}

TEST(SpriteSheetComponentTest, spritesheet_fourth_item_should_be_parsed_properly)
{
    AssetPath path = AssetPath::create("Content\\testspritesheet.xml");
    auto component = XMLSpritesheetParserFactory::create(path);

    auto result = component->get_spriteRect("anim_4");

    ASSERT_EQ(100, result.get_x());
    ASSERT_EQ(0, result.get_y());
    ASSERT_EQ(50, result.get_width());
    ASSERT_EQ(50, result.get_height());
}

TEST(SpriteSheetComponentTest, spritesheet_last_item_should_be_parsed_properly)
{
    AssetPath path = AssetPath::create("Content\\testspritesheet.xml");
    auto component = XMLSpritesheetParserFactory::create(path);

    auto result = component->get_spriteRect("anim_8");

    ASSERT_EQ(150, result.get_x());
    ASSERT_EQ(100, result.get_y());
    ASSERT_EQ(50, result.get_width());
    ASSERT_EQ(50, result.get_height());
}