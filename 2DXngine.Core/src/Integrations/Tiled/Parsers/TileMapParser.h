#pragma once
#include "../../../../../libs/pugixml/src/pugixml.hpp"
#include "ObjectGroupParser.h"
#include "ImageLayerParser.h"
class TiledMap;

class TileMapParser
{
public:
    TileMapParser();
    ~TileMapParser();
    TiledMap* parse(pugi::xml_node& node);
private:
    TiledMap* parseTiledMapAttributes(pugi::xml_node& node);
    ObjectGroupParser _groupParser;
    ImageLayerParser _imageLayerParser;
};

