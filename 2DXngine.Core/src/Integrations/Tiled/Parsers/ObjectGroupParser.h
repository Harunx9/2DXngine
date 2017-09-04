#pragma once
#include "../DataStructures/ObjectLayer.h"
#include "../../pugixml/src/pugixml.hpp"
#include "PropertiesParser.h"

class MapObjectParser
{
public:
    MapObjectParser();
    ~MapObjectParser();

    MapObject parse(pugi::xml_node& node);
private:
    MapObject paseMapObjectAttributes(pugi::xml_node& node);
};

class ObjectGroupParser
{
public:
    ObjectGroupParser();
    ~ObjectGroupParser();

    ObjectGroup parse(pugi::xml_node& node);
private:
    ObjectGroup parseObjectGroup(pugi::xml_node& node);
    PropertiesParser _propParser;
    MapObjectParser _mapObjectParser;
};

