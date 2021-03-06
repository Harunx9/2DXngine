#pragma once
#include "../DataStructures/ImageLayer.h"
#include "../../../../../thirdparty/pugixml/src/pugixml.hpp"
#include "PropertiesParser.h"
class ImageLayerParser
{
public:
    ImageLayerParser();
    ~ImageLayerParser();
    ImageLayer parse(const pugi::xml_node& node);
private:
    ImageLayer parseAttributes(const pugi::xml_node& node);
    TmxImage parseTmxImage(const pugi::xml_node& node);
    PropertiesParser _propParser;
};

