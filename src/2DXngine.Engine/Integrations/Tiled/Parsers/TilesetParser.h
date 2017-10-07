#pragma once
#include "../../thirdparty/pugixml/src/pugixml.hpp"
#include "../DataStructures/TileSet.h"
class TilesetParser
{
public:
    TilesetParser();
    ~TilesetParser();

    TileSet parse(pugi::xml_node& node);
private:
    TileSet parseAttributes(pugi::xml_node& node);
    TmxImage parseImage(pugi::xml_node& node);
    TileOffset parseOffset(pugi::xml_node& node);
};
