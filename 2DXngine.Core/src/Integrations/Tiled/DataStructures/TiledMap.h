#pragma once
#include <map>
#include "TileLayer.h"
#include "Group.h"
#include "ObjectLayer.h"
#include "../../../Utils/Macros/PropertyMacro.h"

enum class Orientation
{
    ORTOGNAL,
    ISOMETRIC,
    STAGGERED,
    HEXAGONAL
};


enum class RenderOrder
{
    RIGHT_DOWN,
    RIGHT_UP,
    LEFT_DOWN,
    LEFT_UP
};

class TiledMap
{
public:
    TiledMap(
        std::string version,
        std::string tiledVersion,
        Orientation orientation,
        RenderOrder renderOrder,
        int width, int height,
        int tileWidth, int tileHeight,
        Color backgroundColor,
        int hexSideLength,
        std::string staggerAxis,
        std::string staggerIndex) :
        _version(version),
        _tiledVersion(tiledVersion),
        _orientation(orientation),
        _renderOrder(renderOrder),
        _width(width), _height(height),
        _tileWidth(tileWidth), _tileHeight(tileHeight),
        _backgroundColor(backgroundColor),
        _hexSideLength(hexSideLength),
        _staggerAxis(staggerAxis),
        _staggerIndex(staggerIndex)
    {
        this->_groups = std::map<std::string, Group>();
        this->_tileLayers = std::map<std::string, TileLayer>();
        this->_objects = std::map<std::string, ObjectGroup>();
        this->_images = std::map<std::string, ImageLayer>();
        this->_properties = std::map<std::string, Property>();
    }

    ~TiledMap() 
    {

    }

    inline void addGroup(const Group group)
    {
        this->_groups[group.get_name()] = group;
    }

    inline Group getGroup(const std::string name)
    {
        return  this->_groups[name];
    }

    inline void addProperty(const Property prop)
    {
        this->_properties[prop.get_name()] = prop;
    }

    inline Property getProperty(const std::string name)
    {
        return  this->_properties[name];
    }

    inline void addTileLayer(const TileLayer tileLayer)
    {
        this->_tileLayers[tileLayer.get_name()] = tileLayer;
    }

    inline TileLayer getTileLayer(const std::string name)
    {
        return  this->_tileLayers[name];
    }

    inline void addObjectGroup(const ObjectGroup objectGroup)
    {
        this->_objects[objectGroup.get_name()] = objectGroup;
    }

    inline ObjectGroup getObjectGroup(const std::string name)
    {
        return  this->_objects[name];
    }

    inline void addImageLayer(const ImageLayer imageLayer)
    {
        this->_images[imageLayer.get_name()] = imageLayer;
    }

    inline ImageLayer getImageLayer(const std::string name)
    {
        return this->_images[name];
    }

    READONLY_PROPERTY(std::string, version)
    READONLY_PROPERTY(std::string, tiledVersion)
    READONLY_PROPERTY(Orientation, orientation)
    READONLY_PROPERTY(RenderOrder, renderOrder)
    READONLY_PROPERTY(int, width)
    READONLY_PROPERTY(int, height)
    READONLY_PROPERTY(int, tileWidth)
    READONLY_PROPERTY(int, tileHeight)
    READONLY_PROPERTY(Color, backgroundColor)
    READONLY_PROPERTY(int, hexSideLength)
    READONLY_PROPERTY(std::string, staggerAxis)
    READONLY_PROPERTY(std::string, staggerIndex)
private:
    std::map<std::string, Group> _groups;
    std::map<std::string, TileLayer> _tileLayers;
    std::map<std::string, ObjectGroup> _objects;
    std::map<std::string, ImageLayer> _images;
    std::map<std::string, Property> _properties;
};

