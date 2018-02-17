#pragma once
#include "../DataStructures/ObjectLayer.h"
#include "../../../../../thirdparty/pugixml/src/pugixml.hpp"
#include "PropertiesParser.h"

class MapObjectParser
{
public:
    MapObjectParser();
    ~MapObjectParser();

    MapObject parse(const pugi::xml_node& node);
private:
    struct PointObject
    {
        std::vector<TmxPoint> parsedPoints;
        ObjectType type;
    };
    
    MapObject parsePolylineObject(const pugi::xml_node& node, const pugi::xml_node& lastChild);
    MapObject parseTextObject(const pugi::xml_node& node, const pugi::xml_node& lastChild);
    TmxText parseTmxText(const pugi::xml_node& node);
    PointObject parsePointObject(const pugi::xml_node& node);
    MapObject parsePlainMapObject(const pugi::xml_node& node);
    PropertiesParser _propParser;
};

class ObjectGroupParser
{
public:
    ObjectGroupParser();
    ~ObjectGroupParser();

    ObjectGroup parse(const pugi::xml_node& node);
private:
    ObjectGroup parseObjectGroup(const pugi::xml_node& node);
    PropertiesParser _propParser;
    MapObjectParser _mapObjectParser;
};

