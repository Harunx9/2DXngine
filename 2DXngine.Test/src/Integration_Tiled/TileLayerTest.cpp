#include "gtest\gtest.h"
#include "TiledFixture.h"
#include <algorithm>

TEST_F(TiledFixture, tile_layer_should_be_parsed)
{
    auto tiles = _parsedMap->getTileLayer("TestTilles");

    ASSERT_EQ(tiles.get_name(), "TestTilles");
    ASSERT_EQ(tiles.get_width(), 10);
    ASSERT_EQ(tiles.get_height(), 10);
}

TEST_F(TiledFixture, tile_layer_data_should_be_parsed)
{
    auto tiles = _parsedMap->getTileLayer("TestTilles");
    
    auto data = tiles.get_data();
    
    ASSERT_EQ(data.tiles.size(), 100);
    ASSERT_FALSE(std::any_of(data.tiles.begin(), data.tiles.end(), [=](Tile tile) {return tile.id == 0; }));
}