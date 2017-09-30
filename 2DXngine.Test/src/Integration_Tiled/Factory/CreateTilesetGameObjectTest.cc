#pragma once
#include "FactoryTestFixture.h"
#include <ComponentModel\GameObject.h>
#include <Integrations\Tiled\Components\TileSetComponent.h>
#include <Integrations\Tiled\Factories\TilesetsFactory.h>

TEST_F(FactoryTestFixture, should_parse_1_tileset)
{
    auto factory = new TilesetsFactory();

    auto result = factory->map(this->_parsedMap);

    ASSERT_EQ(1, result.size());
}


TEST_F(FactoryTestFixture, tilesets_is_constructed_properly)
{
    auto factory = new TilesetsFactory();
    auto vec = factory->map(this->_parsedMap);

    auto result = vec[0]->findFirstComponentOfType<TileSetComponent>();
    result->initialize();

    ASSERT_EQ(result->get_name(), "TileSetComponent");
    ASSERT_EQ(result->get_fileName(), "GreenlandTileset");
    ASSERT_EQ(result->get_tileHeight(), 16);
    ASSERT_EQ(result->get_tileWidth(), 32);
}