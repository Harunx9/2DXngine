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
    struct PointObject
    {
        std::vector<TmxPoint> parsedPoints;
        ObjectType type;
    };
    
    MapObject parsePolylineObject(pugi::xml_node& node, pugi::xml_node& lastChild);
    MapObject parseTextObject(pugi::xml_node& node, pugi::xml_node& lastChild);
    TmxText parseTmxText(pugi::xml_node& node);
    PointObject parsePointObject(pugi::xml_node& node);
    MapObject parsePlainMapObject(pugi::xml_node& node);
    PropertiesParser _propParser;
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

