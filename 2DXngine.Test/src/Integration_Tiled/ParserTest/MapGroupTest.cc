#include "gtest\gtest.h"
#include "TiledFixture.h"
#include <algorithm>

TEST_F(TiledFixture, Group_should_be_parsed_with_items)
{
    auto group = _parsedMap->getGroup("TestGroup");

    auto layer = group.getTileLayer("Tile Layer 2");
    auto objectGroup = group.getObjectGroup("Object Layer 2");

    ASSERT_EQ(group.get_name(), "TestGroup");
    ASSERT_EQ(layer.get_name(), "Tile Layer 2");
    ASSERT_EQ(objectGroup.get_name(), "Object Layer 2");
}

TEST_F(TiledFixture, Group_TileLayer_should_be_parsed)
{
    auto group = _parsedMap->getGroup("TestGroup");

    auto layer = group.getTileLayer("Tile Layer 2");

    auto data = layer.get_data();
    int count = std::count_if(data.tiles.begin(),
        data.tiles.end(),
        [=](Tile tile) { return tile.id != 0; });
    ASSERT_EQ(layer.get_name(), "Tile Layer 2");
    ASSERT_EQ(layer.get_data().tiles.size(), 100);
    ASSERT_TRUE(count > 0);
}

TEST_F(TiledFixture, Group_ObjectLayer_should_be_parsed_with_items)
{
    auto group = _parsedMap->getGroup("TestGroup");

    auto objectGroup = group.getObjectGroup("Object Layer 2");

    ASSERT_EQ(objectGroup.get_name(), "Object Layer 2");
    ASSERT_EQ(objectGroup.get_objects().size(), 2);
}