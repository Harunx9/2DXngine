#pragma once
#include "ObjectGroupParser.h"
#include "TileLayerParser.h"
#include "ImageLayerParser.h"
#include "../DataStructures/Group.h"


class GroupParser
{
public:
    GroupParser();
    ~GroupParser();
    Group parse(pugi::xml_node& node);
private:
    Group parseAttributes(pugi::xml_node& node);
    ObjectGroupParser _groupParser;
    ImageLayerParser _imageLayerParser;
    TileLayerParser _tileLayerParser;
    PropertiesParser _propParser;
};

