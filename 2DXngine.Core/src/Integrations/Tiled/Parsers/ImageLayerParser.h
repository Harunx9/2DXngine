#pragma once
#include "../DataStructures/ImageLayer.h"
#include "../../../../../libs/pugixml/src/pugixml.hpp"
#include "PropertiesParser.h"
class ImageLayerParser
{
public:
    ImageLayerParser();
    ~ImageLayerParser();
    ImageLayer parse(pugi::xml_node& node);
private:
    ImageLayer parseAttributes(pugi::xml_node& node);
    TmxImage parseTmxImage(pugi::xml_node& node);
    PropertiesParser _propParser{};
};

