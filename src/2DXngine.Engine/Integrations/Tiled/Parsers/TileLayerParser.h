#pragma once
#include "../DataStructures/TileLayer.h"
#include "../../thirdparty/pugixml/src/pugixml.hpp"
#include "PropertiesParser.h"

class TileLayerParser
{
public:
    TileLayerParser();
    ~TileLayerParser();
    TileLayer parse(const pugi::xml_node& node);

private:
    TileLayer parseAttributes(const pugi::xml_node& node);
    Data parseData(const pugi::xml_node& node);
    Data parseBase64(const pugi::xml_node& node);
    Data parseCSV(const pugi::xml_node& node);
    PropertiesParser _propParser;
};

