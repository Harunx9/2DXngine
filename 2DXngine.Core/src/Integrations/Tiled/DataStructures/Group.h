#pragma once
#include <string>
#include <map>
#include <functional>
#include <algorithm>
#include "../../../Utils/Macros/PropertyMacro.h"
#include "TileLayer.h"
#include "ObjectLayer.h"
#include "ImageLayer.h"

class Group
{
public:
    Group() {}
    Group(std::string name,
        int offsetX,
        int offsetY,
        float opacity,
        bool visible) :
        _name(name),
        _offsetX(offsetX),
        _offsetY(offsetY),
        _opacity(opacity),
        _visible(visible)
    {
        this->_groups = std::map<std::string, Group>();
        this->_tileLayers = std::map<std::string, TileLayer>();
        this->_objects = std::map<std::string, ObjectGroup>();
        this->_images = std::map<std::string, ImageLayer>();
        this->_properties = std::map<std::string, Property>();
    }

    ~Group()
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

    inline void addProperties(const std::vector<Property> props)
    {
        for (auto& prop : props)
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

    std::vector<TileLayer> get_AllTileLayers()
    {
        std::vector<TileLayer> vec;

        std::transform(
            this->_tileLayers.begin(),
            this->_tileLayers.end(),
            std::back_inserter(vec),
            [&](auto &x) {return x.second; });

        for (auto& group : _groups)
        {
            auto g = group.second.get_AllTileLayers();
            vec.insert(vec.end(), g.begin(), g.end());
        }

        return vec;
    }

    READONLY_PROPERTY(std::string, name)
    READONLY_PROPERTY(int, offsetX)
    READONLY_PROPERTY(int, offsetY)
    READONLY_PROPERTY(float, opacity)
    READONLY_PROPERTY(bool, visible)

private:
    std::map<std::string, Group> _groups;
    std::map<std::string, TileLayer> _tileLayers;
    std::map<std::string, ObjectGroup> _objects;
    std::map<std::string, ImageLayer> _images;
    std::map<std::string, Property> _properties;
};
