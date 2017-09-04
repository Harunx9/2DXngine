#pragma once
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
#include "../../../Utils/Macros/PropertyMacro.h"
#include "../../../Graphics/Color.h"
#include "Property.h"

enum ObjectType
{
    OBJECT,
    TILE,
    ELLIPSE,
    POLYGON,
    POLYLINE,
    TEXT
};

enum VerticalAlign
{
    VA_TOP,
    VA_CENTER,
    VA_BOTTOM
};

enum HorizontalAling
{
    HA_LEFT,
    HA_CENTER,
    HA_RIGHT
};

enum DrawOrder
{
    TOP_DOWN,
    INDEX
};

struct TmxPoint
{
    int x;
    int y;
};

struct TmxText
{
    std::string fontFamily;
    int pixelSize;
    bool wrap;
    Color color;
    bool bold;
    bool italic;
    bool underline;
    bool strikeout;
    bool kerning;
    VerticalAlign valign;
    HorizontalAling halign;
};

class MapObject
{
public:
    MapObject(int id,
        std::string name,
        std::string type,
        int x, int y,
        int width, int height,
        float rotation,
        bool visible,
        ObjectType tmxtype = ObjectType::OBJECT) :
        _id(id),
        _name(name),
        _type(type),
        _x(x), _y(y),
        _width(width), _height(height),
        _rotation(rotation),
        _visible(visible),
        _tmxtype(tmxtype)
    {
    }

    MapObject(int id,
        std::string name,
        std::string type,
        int x, int y,
        int width, int height,
        float rotation,
        bool visible,
        std::vector<TmxPoint> points,
        ObjectType tmxtype) :
        MapObject(id, name, type, x, y, width, height, rotation, visible, tmxtype)
    {
        _points = points;
    }

    MapObject(int id,
        std::string name,
        std::string type,
        int x, int y,
        int width, int height,
        float rotation,
        bool visible,
        TmxText text) :
        MapObject(id, name, type, x, y, width, height, rotation, visible, ObjectType::TEXT)
    {
        _text = text;
    }

    ~MapObject()
    {
    }

    READONLY_PROPERTY(int, id)
        READONLY_PROPERTY(std::string, name)
        READONLY_PROPERTY(std::string, type)
        READONLY_PROPERTY(int, x)
        READONLY_PROPERTY(int, y)
        READONLY_PROPERTY(int, width)
        READONLY_PROPERTY(int, height)
        READONLY_PROPERTY(float, rotation)
        READONLY_PROPERTY(bool, visible)
        READONLY_PROPERTY(std::vector<TmxPoint>, points)
        READONLY_PROPERTY(ObjectType, tmxtype)
        READONLY_PROPERTY(TmxText, text)
};


class ObjectGroup
{
public:
    ObjectGroup(
        std::string name,
        Color color,
        int x, int y,
        int width, int height,
        float opacity,
        bool visible,
        int offsetx, int offsety,
        DrawOrder draworder) :
        _name(name),
        _color(color),
        _x(x), _y(y),
        _width(width), _height(height),
        _opacity(opacity),
        _visible(visible),
        _offsetx(offsetx),
        _offsety(offsety),
        _draworder(draworder)
    {
        this->_objects = std::vector<MapObject>();
    }

    ~ObjectGroup()
    {

    }

    void addProperties(const std::vector<Property> props)
    {
        for (auto& prop : props)
            this->_properties[prop.get_name()] = prop;
    }

    void addProperty(const Property prop)
    {
        this->_properties[prop.get_name()] = prop;
    }

    Property getProperty(const std::string name)
    {
        return _properties[name];
    }

    void addObject(MapObject object)
    {
        this->_objects.push_back(object);
    }

    MapObject findObject(std::function<bool(MapObject)> pred)
    {
        auto  it = std::find_if(this->_objects.begin(), this->_objects.end(), pred);
        return *it;
    }

    std::vector<MapObject> filterObject(std::function<bool(MapObject)> pred)
    {
        auto retvec = std::vector<MapObject>();
        for (auto& obj : this->_objects)
        {
            if (pred(obj))
            {
                retvec.push_back(obj);
            }
        }

        return retvec;
    }

    READONLY_PROPERTY(std::string, name)
        READONLY_PROPERTY(Color, color)
        READONLY_PROPERTY(int, x)
        READONLY_PROPERTY(int, y)
        READONLY_PROPERTY(int, width)
        READONLY_PROPERTY(int, height)
        READONLY_PROPERTY(float, opacity)
        READONLY_PROPERTY(bool, visible)
        READONLY_PROPERTY(int, offsetx)
        READONLY_PROPERTY(int, offsety)
        READONLY_PROPERTY(DrawOrder, draworder)
        READONLY_PROPERTY(std::vector<MapObject>, objects)

private:
    std::map<std::string, Property> _properties;
};