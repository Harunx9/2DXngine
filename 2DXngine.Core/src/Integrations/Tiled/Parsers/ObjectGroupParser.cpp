#include "ObjectGroupParser.h"

ObjectGroupParser::ObjectGroupParser()
{
}

ObjectGroupParser::~ObjectGroupParser()
{
}

ObjectGroup ObjectGroupParser::parseObjectGroup(pugi::xml_node& node)
{
    auto name = node.attribute("name");
    auto color = node.attribute("color");
    auto x = node.attribute("x");
    auto y = node.attribute("y");
    auto width = node.attribute("width");
    auto height = node.attribute("height");
    auto opacity = node.attribute("opacity");
    auto visible = node.attribute("visible");
    auto offsetx = node.attribute("offsetx");
    auto offsety = node.attribute("offsety");
    auto draworder = node.attribute("draworder");

    DrawOrder order = DrawOrder::TOP_DOWN;
    if (draworder.empty() == false)
    {
        auto val = std::string(draworder.as_string());
        if (val.compare("INDEX") == 0)
        {
            order = DrawOrder::INDEX;
        }
    }

    return ObjectGroup(
        std::string(name.as_string()),
        Color(color.as_string()),
        x.empty() ? 0 : x.as_int(),
        y.empty() ? 0 : y.as_int(),
        width.empty() ? 0 : width.as_int(),
        height.empty() ? 0 : height.as_int(),
        opacity.empty() ? 1.f : opacity.as_float(),
        visible.empty() ? true : height.as_bool(),
        offsetx.empty() ? 0 : offsetx.as_int(),
        offsety.empty() ? 0 : offsety.as_int(),
        order);
}

ObjectGroup ObjectGroupParser::parse(pugi::xml_node& node)
{
    auto group = parseObjectGroup(node);

    auto properties = node.child("properties");
    if (properties.empty() == false)
    {
        auto parsedProps = this->_propParser.parse(node);
        group.addProperties(parsedProps);
    }

    auto objects = node.children("object");
    for (auto & objectNode : objects)
    {
        auto object = _mapObjectParser.parse(objectNode);
        group.addObject(object);
    }

    return group;
}
