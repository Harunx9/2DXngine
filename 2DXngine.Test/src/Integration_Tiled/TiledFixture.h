#pragma once
#include "gtest\gtest.h"
#include "../pugixml/src/pugixml.hpp"
#include <Integrations\Tiled\Parsers\TileMapParser.h>
#include <Integrations\Tiled\DataStructures\TiledMap.h>

class TiledFixture : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        pugi::xml_document doc;
        auto parseResult = doc.load_file("./Content/TestMap.tmx");

        auto parser = TileMapParser();
        this->_parsedMap = parser.parse(doc.child("map"));
    }

    virtual void TearDown()
    {
        delete _parsedMap;
    }

    TiledMap * _parsedMap;
};


