#pragma once
#include "../../../../../libs/pugixml/src/pugixml.hpp"
#include "ObjectGroupParser.h"
#include "ImageLayerParser.h"
#include "TileLayerParser.h"
#include "GroupParser.h"
class TiledMap;

class TileMapParser
{
public:
    TileMapParser();
    ~TileMapParser();
    TiledMap* parse(pugi::xml_node& node);
private:
    TiledMap* parseTiledMapAttributes(pugi::xml_node& node);
    GroupParser _groupParser;
    ObjectGroupParser _objectGroupParser;
    ImageLayerParser _imageLayerParser;
    TileLayerParser _tileLayerParser;
    PropertiesParser _propParser;
};

