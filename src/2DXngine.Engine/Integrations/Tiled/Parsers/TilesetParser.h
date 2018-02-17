#pragma once
#include "../../../../../thirdparty/pugixml/src/pugixml.hpp"
#include "../DataStructures/TileSet.h"
class TilesetParser
{
public:
    TilesetParser();
    ~TilesetParser();

    TileSet parse(const pugi::xml_node& node);
private:
    TileSet parseAttributes(const pugi::xml_node& node);
    TmxImage parseImage(const pugi::xml_node& node);
    TileOffset parseOffset(const pugi::xml_node& node);
};
