#pragma once
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include "../../../Utils/Macros/PropertyMacro.h"
#include "Property.h"

struct Tile
{
    int id;
};

struct Data
{
    std::vector<Tile> tiles;
};

class TileLayer
{
public:
    TileLayer() {};
    TileLayer(
        std::string name,
        int x, int y,
        int width, int height,
        float opacity,
        bool visible,
        int offsetx, int offsety):
        _name(name),
        _x(x), _y(y),
        _width(width), _height(height),
        _opacity(opacity),
        _visible(visible),
        _offsetx(offsetx), _offsety(offsety)
    {
    }

    ~TileLayer()
    {
    }

    void addProperties(const std::vector<Property> props)
    {
        for (auto& prop : props)
            this->_properties[prop.get_name()] = prop;
    }


    Property getProperty(const std::string name)
    {
        return _properties[name];
    }
    
    int ** to2DArray()
    {
        int ** arr = new int*[this->_height];
        for (size_t r = 0; r <(size_t) this->_height; ++r)
            arr[r] = new int[this->_width];

        int row = 0; 
        int col = 0;
        for (auto& tileId : this->_data.tiles)
        {
            if (col >= this->_width)
            {
                ++row;
                col = 0;
            }

            arr[row][col] = tileId.id;

            ++col;
        }

        return arr;
    }

    PROPERTY(Data, data)
    READONLY_PROPERTY(std::string, name)
    READONLY_PROPERTY(int, x)
    READONLY_PROPERTY(int, y)
    READONLY_PROPERTY(int, width)
    READONLY_PROPERTY(int, height)
    READONLY_PROPERTY(float, opacity)
    READONLY_PROPERTY(bool, visible)
    READONLY_PROPERTY(int, offsetx)
    READONLY_PROPERTY(int, offsety)

private:
    std::map<std::string, Property> _properties;
};
