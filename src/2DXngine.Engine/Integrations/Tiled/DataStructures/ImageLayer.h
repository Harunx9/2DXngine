#pragma once
#include <string>
#include <map>
#include <vector>
#include "../../../Utils/Macros/PropertyMacro.h"
#include "../../../Graphics/Color.h"
#include "Property.h"

struct TmxImage
{
    std::string format;
    std::string source;
    Color trans;
    int width = 0;
    int height = 0;

    TmxImage() : trans(Color("#FF00FF")) {}
    TmxImage(std::string format,
        std::string source,
        Color trans,
        int width, int height):
        format(format),
        source(source),
        trans(trans),
        width(width),
        height(height)
        {}
}; 


class ImageLayer
{
public:
    ImageLayer() {}
    ImageLayer(std::string name,
        int offsetX, int offsetY,
        float opacity,
        bool visible):
        _name(name),
        _offsetX(offsetX), _offsetY(offsetY),
        _opacity(opacity),
        _visible(visible)
    {
    }

    ~ImageLayer()
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

    PROPERTY(TmxImage, image)
    READONLY_PROPERTY(std::string, name)
    READONLY_PROPERTY(int, offsetX)
    READONLY_PROPERTY(int, offsetY)
    READONLY_PROPERTY(float, opacity)
    READONLY_PROPERTY(bool, visible)

private:
    std::map<std::string, Property> _properties;
};
