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

MapObjectParser::MapObjectParser()
{
}

MapObjectParser::~MapObjectParser()
{
}

MapObject MapObjectParser::parse(pugi::xml_node & node)
{
    auto lastChild = node.last_child();
    MapObject obj;
    auto name = std::string(lastChild.name());
    if (name.compare("properties") != 0)
    {
        if (name.compare("text") != 0)
        {
            obj = this->parsePolylineObject(node, lastChild);
        }
        else
        {
            obj = this->parseTextObject(node, lastChild);
        }
    }
    else
    {
        obj = this->parsePlainMapObject(node);
    }

    auto properties = node.child("properties");
    if (properties.empty() == false)
    {
        auto parsedProps = this->_propParser.parse(node);
        obj.addProperties(parsedProps);
    }

    return obj;
}

MapObject MapObjectParser::parsePolylineObject(pugi::xml_node & node, pugi::xml_node & lastChild)
{
    auto id = node.attribute("id");
    auto name = node.attribute("name");
    auto type = node.attribute("type");
    auto x = node.attribute("x");
    auto y = node.attribute("y");
    auto width = node.attribute("width");
    auto height = node.attribute("height");
    auto rotation = node.attribute("rotation");
    auto visible = node.attribute("visible");



    return MapObject(
        id.as_int(),
        name.empty() ? "" : std::string(name.as_string()),
        type.empty() ? "" : std::string(type.as_string()),
        x.as_int(),
        y.as_int(),
        width.empty() ? 0 : width.as_int(),
        height.empty() ? 0 : height.as_int(),
        rotation.empty() ? 0.f : rotation.as_float(),
        visible.empty() ? true : visible.as_bool()
    );
}

MapObject MapObjectParser::parseTextObject(pugi::xml_node & node, pugi::xml_node & lastChild)
{
    auto id = node.attribute("id");
    auto name = node.attribute("name");
    auto type = node.attribute("type");
    auto x = node.attribute("x");
    auto y = node.attribute("y");
    auto width = node.attribute("width");
    auto height = node.attribute("height");
    auto rotation = node.attribute("rotation");
    auto visible = node.attribute("visible");

    TmxText text = this->parseTmxText(lastChild);

    return MapObject(
        id.as_int(),
        name.empty() ? "" : std::string(name.as_string()),
        type.empty() ? "" : std::string(type.as_string()),
        x.as_int(),
        y.as_int(),
        width.empty() ? 0 : width.as_int(),
        height.empty() ? 0 : height.as_int(),
        rotation.empty() ? 0.f : rotation.as_float(),
        visible.empty() ? true : visible.as_bool(),
        text
    );
}

TmxText MapObjectParser::parseTmxText(pugi::xml_node & node)
{
    auto text_fontfamily = node.attribute("fontfamily");
    auto text_pixelsize = node.attribute("pixelsize");
    auto text_wrap = node.attribute("wrap");
    auto text_color = node.attribute("color");
    auto text_bold = node.attribute("bold");
    auto text_italic = node.attribute("italic");
    auto text_underline = node.attribute("underline");
    auto text_strikeout = node.attribute("strikeout");
    auto text_kerning = node.attribute("kerning");
    auto text_halign = node.attribute("halign");
    auto text_valign = node.attribute("valign");
    auto text_value = std::string(node.value());

    VerticalAlign va = VA_TOP;
    HorizontalAling ha = HA_LEFT;

    if (text_halign.empty() == false)
    {
        auto val = std::string(text_halign.as_string());
        if (val.compare("center"))
        {
            ha = HA_CENTER;
        }
        if (val.compare("right"))
        {
            ha = HA_RIGHT;
        }
    }

    if (text_valign.empty() == false)
    {
        auto val = std::string(text_valign.as_string());
        if (val.compare("center"))
        {
            va = VA_CENTER;
        }
        if (val.compare("bottom"))
        {
            va = VA_BOTTOM;
        }
    }

    return {
        text_fontfamily.empty() ? "sans-serif" : std::string(text_fontfamily.value()),
        text_pixelsize.empty() ? 16 : text_pixelsize.as_int(),
        text_wrap.empty() ? false : text_wrap.as_bool(),
        text_color.empty() ? Color("#000000") : Color(std::string(text_color.as_string())),
        text_bold.empty() ? false : text_bold.as_bool(),
        text_italic.empty() ? false : text_italic.as_bool(),
        text_underline.empty() ? false : text_underline.as_bool(),
        text_strikeout.empty() ? false : text_strikeout.as_bool(),
        text_kerning.empty() ? true : text_kerning.as_bool(),
        va,
        ha,
        text_value
    };
}

MapObjectParser::PointObject MapObjectParser::parsePointObject(pugi::xml_node & node)
{
    return PointObject();
}

MapObject MapObjectParser::parsePlainMapObject(pugi::xml_node & node)
{
    auto id = node.attribute("id");
    auto name = node.attribute("name");
    auto type = node.attribute("type");
    auto x = node.attribute("x");
    auto y = node.attribute("y");
    auto width = node.attribute("width");
    auto height = node.attribute("height");
    auto rotation = node.attribute("rotation");
    auto visible = node.attribute("visible");

    return MapObject(
        id.as_int(),
        name.empty() ? "" : std::string(name.as_string()),
        type.empty() ? "" : std::string(type.as_string()),
        x.as_int(),
        y.as_int(),
        width.empty() ? 0 : width.as_int(),
        height.empty() ? 0 : height.as_int(),
        rotation.empty() ? 0.f : rotation.as_float(),
        visible.empty() ? true : visible.as_bool()
    );
}
