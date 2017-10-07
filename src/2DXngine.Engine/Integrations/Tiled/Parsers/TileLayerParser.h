#pragma once
#include "../DataStructures/TileLayer.h"
#include "../../thirdparty/pugixml/src/pugixml.hpp"
#include "PropertiesParser.h"

class TileLayerParser
{
public:
    TileLayerParser();
    ~TileLayerParser();
    TileLayer parse(pugi::xml_node& node);

private:
    TileLayer parseAttributes(pugi::xml_node& node);
    Data parseData(pugi::xml_node& node);
    Data parseBase64(pugi::xml_node& node);
    Data parseCSV(pugi::xml_node& node);
    PropertiesParser _propParser;
};

