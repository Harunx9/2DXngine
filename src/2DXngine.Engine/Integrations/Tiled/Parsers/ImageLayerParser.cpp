#include "ImageLayerParser.h"

namespace ImageLayerConsts {
    const char* name = "name";
    const char* offset_x = "offsetx";
    const char* offset_y = "offsety";
    const char* opacity = "opacity";
    const char* visible = "visible";
}

namespace TmxImageConsts {
    const char* format = "format";
    const char* source = "source";
    const char* trans = "trans";
    const char* width = "width";
    const char* height = "height";
}

ImageLayerParser::ImageLayerParser()
{
}

ImageLayerParser::~ImageLayerParser()
{
}

ImageLayer ImageLayerParser::parse(const pugi::xml_node & node)
{
    ImageLayer layer = this->parseAttributes(node);

    auto properties = node.child("properties");
    if (properties.empty() == false)
    {
        auto parsedProps = this->_propParser.parse(node);
        layer.addProperties(parsedProps);
    }

    auto lastChild = node.last_child();
    std::string lastChildName = lastChild.name();
    if (lastChildName.compare("image") == 0)
    {
        TmxImage image = this->parseTmxImage(lastChild);
        layer.set_image(image);
    }

    return layer;
}

ImageLayer ImageLayerParser::parseAttributes(const pugi::xml_node & node)
{
    auto name = node.attribute(ImageLayerConsts::name);
    auto offsetX = node.attribute(ImageLayerConsts::offset_x);
    auto offsetY = node.attribute(ImageLayerConsts::offset_y);
    auto opacity = node.attribute(ImageLayerConsts::opacity);
    auto visible = node.attribute(ImageLayerConsts::visible);

    return {
        std::string(name.as_string()),
        offsetX.empty() ? 0 : offsetX.as_int(),
        offsetY.empty() ? 0 : offsetY.as_int(),
        opacity.empty() ? 1.f : opacity.as_float(),
        visible.empty() ? true : visible.as_bool(),
    };
}

TmxImage ImageLayerParser::parseTmxImage(const pugi::xml_node & node)
{
    auto format = node.attribute(TmxImageConsts::format);
    auto source = node.attribute(TmxImageConsts::source);
    auto trans = node.attribute(TmxImageConsts::trans);
    auto width = node.attribute(TmxImageConsts::width);
    auto height = node.attribute(TmxImageConsts::height);

    return {
        format.empty() ? "" : std::string(format.as_string()),
        source.empty() ? "" : std::string(source.as_string()),
        trans.empty() ? Color("#FF00FF") : Color(std::string(trans.as_string())),
        width.empty() ? 0 : width.as_int(),
        height.empty() ? 0 : height.as_int()
    };
}
