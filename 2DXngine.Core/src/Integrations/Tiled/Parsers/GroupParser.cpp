#include "GroupParser.h"

namespace GroupConsts
{
    const char * name = "name";
    const char * offset_x = "offsetx";
    const char * offset_y = "offsety";
    const char * opacity = "opacity";
    const char * visible = "visible";
}

GroupParser::GroupParser()
{
}


GroupParser::~GroupParser()
{
}

Group GroupParser::parse(pugi::xml_node & node)
{
    Group group = this->parseAttributes(node);

    auto properties = node.child("properties");
    if (properties.empty() == false)
    {
        auto parsedProps = this->_propParser.parse(node);
        group.addProperties(parsedProps);
    }

    auto objects = node.children("objectgroup");
    for (auto& obj : objects)
    {
        group.addObjectGroup(this->_groupParser.parse(obj));
    }

    auto images = node.children("imagelayer");
    for (auto& img : images)
    {
        group.addImageLayer(this->_imageLayerParser.parse(img));
    }

    auto layers = node.children("layer");
    for (auto& layer : layers)
    {
        group.addTileLayer(this->_tileLayerParser.parse(layer));
    }

    auto groups = node.children("group");
    for (auto& group_node : groups)
    {
        group.addGroup(this->parse(group_node));
    }

    return group;
}

Group GroupParser::parseAttributes(pugi::xml_node & node)
{
    auto name = node.attribute(GroupConsts::name);
    auto offsetX = node.attribute(GroupConsts::offset_x);
    auto offsetY = node.attribute(GroupConsts::offset_y);
    auto opacity = node.attribute(GroupConsts::opacity);
    auto visible = node.attribute(GroupConsts::visible);

    return {
        std::string(name.as_string()),
        offsetX.empty() ? 0 : offsetX.as_int(),
        offsetY.empty() ? 0 : offsetY.as_int(),
        opacity.empty() ? 1.f : opacity.as_float(),
        visible.empty() ? true : visible.as_bool()
    };
}
