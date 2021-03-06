#include "gtest/gtest.h"
#include "TiledFixture.h"

TEST_F(TiledFixture, map_attributes_should_be_parsed)
{

    ASSERT_EQ("1.0", _parsedMap->get_version());
    ASSERT_EQ("1.0.3", _parsedMap->get_tiledVersion());
    ASSERT_EQ(Orientation::ORTOGNAL, _parsedMap->get_orientation());
    ASSERT_EQ(RenderOrder::RIGHT_DOWN, _parsedMap->get_renderOrder());
    ASSERT_EQ(10, _parsedMap->get_width());
    ASSERT_EQ(10, _parsedMap->get_height());
    ASSERT_EQ(32, _parsedMap->get_tileWidth());
    ASSERT_EQ(32, _parsedMap->get_tileHeight());
}

TEST_F(TiledFixture, map_should_have_TestObject_parsed)
{
    auto group = _parsedMap->getObjectGroup("TestObject");

    ASSERT_EQ(group.get_name(), "TestObject");
}

TEST_F(TiledFixture, map_should_have_ImageLayer_parsed)
{
    auto img = _parsedMap->getImageLayer("Image Layer 1");

    ASSERT_EQ(img.get_name(), "Image Layer 1");
}

TEST_F(TiledFixture, map_should_have_TileLayer_parsed)
{
    auto tiles = _parsedMap->getTileLayer("TestTilles");

    ASSERT_EQ(tiles.get_name(), "TestTilles");
}

TEST_F(TiledFixture, map_should_have_Group_parsed)
{
    auto group = _parsedMap->getGroup("TestGroup");

    ASSERT_EQ(group.get_name(), "TestGroup");
}