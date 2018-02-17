#pragma once
#include "../../../../../thirdparty/pugixml/src/pugixml.hpp"
#include "ObjectGroupParser.h"
#include "ImageLayerParser.h"
#include "TileLayerParser.h"
#include "GroupParser.h"
#include "TilesetParser.h"
class TiledMap;

class TileMapParser
{
public:
    TileMapParser();
    ~TileMapParser();
    TiledMap* parse(const pugi::xml_node& node);
private:
    TiledMap* parseTiledMapAttributes(const pugi::xml_node& node);
    GroupParser _groupParser;
    ObjectGroupParser _objectGroupParser;
    ImageLayerParser _imageLayerParser;
    TileLayerParser _tileLayerParser;
    TilesetParser _tilesetParser;
    PropertiesParser _propParser;
};

