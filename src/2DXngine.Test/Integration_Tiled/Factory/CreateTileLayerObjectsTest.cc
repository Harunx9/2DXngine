#pragma once
#include "FactoryTestFixture.h"
#include <ComponentModel\GameObject.h>
#include <Integrations\Tiled\Components\TiledLayerComponent.h>
#include <Integrations\Tiled\Factories\TileLayersFactory.h>

TEST_F(FactoryTestFixture, should_parse_3_tilelayers)
{
    auto mapper = new TileLayersFactory();

    auto result = mapper->map(this->_parsedMap);

    ASSERT_EQ(3, result.size());
}

TEST_F(FactoryTestFixture, should_parse_first_layer_properly)
{
    auto mapper = new TileLayersFactory();
    auto vec = mapper->map(this->_parsedMap);

    auto tileLayerComponent = vec[0]->findFirstComponentOfType<TiledLayerComponent>();

    ASSERT_EQ("Tile Layer 1", tileLayerComponent->get_nameLayer());
    ASSERT_EQ(5, tileLayerComponent->get_width());
    ASSERT_EQ(5, tileLayerComponent->get_height());
}

TEST_F(FactoryTestFixture, should_parse_second_layer_properly)
{
    auto mapper = new TileLayersFactory();
    auto vec = mapper->map(this->_parsedMap);

    auto tileLayerComponent = vec[1]->findFirstComponentOfType<TiledLayerComponent>();

    ASSERT_EQ("Tile Layer 2", tileLayerComponent->get_nameLayer());
    ASSERT_EQ(5, tileLayerComponent->get_width());
    ASSERT_EQ(5, tileLayerComponent->get_height());
}


TEST_F(FactoryTestFixture, should_parse_third_layer_properly)
{
    auto mapper = new TileLayersFactory();
    auto vec = mapper->map(this->_parsedMap);

    auto tileLayerComponent = vec[2]->findFirstComponentOfType<TiledLayerComponent>();

    ASSERT_EQ("Tile Layer 3", tileLayerComponent->get_nameLayer());
    ASSERT_EQ(5, tileLayerComponent->get_width());
    ASSERT_EQ(5, tileLayerComponent->get_height());
}