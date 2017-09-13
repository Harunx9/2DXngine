#include "TilesetParser.h"

TilesetParser::TilesetParser()
{
}

TilesetParser::~TilesetParser()
{
}

TileSet TilesetParser::parse(pugi::xml_node & node)
{
    TileSet tileset = this->parseAttributes(node);

    auto offset = node.child("tileoffset");
    if (offset.empty() == false)
    {
        tileset.set_offset(this->parseOffset(offset));
    }

    auto image = node.child("image");
    if (image.empty() == false)
    {
        tileset.set_image(this->parseImage(image));
    }

    return tileset;
}

TileSet TilesetParser::parseAttributes(pugi::xml_node & node)
{
    auto firstgid = node.attribute("firstgid");
    auto source = node.attribute("source");
    auto name = node.attribute("name");
    auto tilewidth = node.attribute("tilewidth");
    auto tileheight = node.attribute("tileheight");
    auto spacing = node.attribute("spacing");
    auto margin = node.attribute("margin");
    auto tilecount = node.attribute("tilecount");
    auto columns = node.attribute("columns");
    
    if (source.empty())
    {

        return {
            firstgid.as_int(),
            std::string(name.as_string()),
            tilewidth.as_int(),
            tileheight.as_int(),
            spacing.as_int(),
            margin.as_int(),
            tilecount.as_int(),
            columns.as_int()
        };
    }
    else
    {
        return {
            firstgid.as_int(),
            std::string(source.as_string())
        };
    }
}

TmxImage TilesetParser::parseImage(pugi::xml_node & node)
{
    auto format = node.attribute("format");
    auto source = node.attribute("source");
    auto trans = node.attribute("trans");
    auto width = node.attribute("width");
    auto height = node.attribute("height");

    return {
        format.empty() ? "" : std::string(format.as_string()),
        source.empty() ? "" : std::string(source.as_string()),
        trans.empty() ? Color("#FF00FF") : Color(std::string(trans.as_string())),
        width.empty() ? 0 : width.as_int(),
        height.empty() ? 0 : height.as_int()
    };
}

TileOffset TilesetParser::parseOffset(pugi::xml_node & node)
{
    auto x = node.attribute("x");
    auto y = node.attribute("y");

    return {
        x.as_int(),
        y.as_int()
    };
}
