#pragma once
#include "gtest\gtest.h"
#include "../pugixml/src/pugixml.hpp"
#include <Integrations\Tiled\Parsers\TileMapParser.h>
#include <Integrations\Tiled\DataStructures\TiledMap.h>
#include <ContentManagement/AssetPath.h>

class FactoryTestFixture : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        AssetPath path = AssetPath::create("Content\\TestMap2.tmx");
        pugi::xml_document doc;
        auto parseResult = doc.load_file(path.get_fullPath().c_str());

        auto parser = TileMapParser();
        this->_parsedMap = parser.parse(doc.child("map"));
    }

    virtual void TearDown()
    {
        delete _parsedMap;
    }

    TiledMap * _parsedMap;
};
