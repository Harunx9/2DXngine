#include "TileMapParser.h"
#include "../DataStructures/TiledMap.h"

namespace TiledMapConsts
{
    const char * element = "map";
    const char * version = "version";
    const char * tiledversion = "tiledversion";
    const char * orientation = "orientation";
    const char * renderorder = "renderorder";
    const char * width = "width";
    const char * height = "height";
    const char * tilewidth = "tilewidth";
    const char * tileheight = "tileheight";
    const char * hexsidelength = "hexsidelength";
    const char * staggeraxis = "staggeraxis";
    const char * staggerindex = "staggerindex";
    const char * backgroundcolor = "backgroundcolor";
    const char * nextobjectid = "nextobjectid";
};

TileMapParser::TileMapParser()
{
}

TileMapParser::~TileMapParser()
{
}

TiledMap* TileMapParser::parse(pugi::xml_node & node)
{
    TiledMap* map = this->parseTiledMapAttributes(node);


    auto properties = node.child("properties");
    if (properties.empty() == false)
    {
        auto parsedProps = this->_propParser.parse(node);
        map->addProperties(parsedProps);
    }

    auto objects = node.children("objectgroup");
    for (auto& obj : objects)
    {
        map->addObjectGroup(this->_groupParser.parse(obj));
    }

    auto images = node.children("imagelayer");
    for (auto& img : images)
    {
        map->addImageLayer(this->_imageLayerParser.parse(img));
    }

    auto layers = node.children("layer");
    for (auto& layer : layers)
    {
        map->addTileLayer(this->_tileLayerParser.parse(layer));
    }

    return map;
}

TiledMap* TileMapParser::parseTiledMapAttributes(pugi::xml_node & node)
{
    auto version = node.attribute(TiledMapConsts::version);
    auto tiledVersion = node.attribute(TiledMapConsts::tiledversion);
    auto orientation = node.attribute(TiledMapConsts::orientation);
    auto renderOrder = node.attribute(TiledMapConsts::renderorder);
    auto width = node.attribute(TiledMapConsts::width);
    auto height = node.attribute(TiledMapConsts::height);
    auto tileWidth = node.attribute(TiledMapConsts::tilewidth);
    auto tileHeight = node.attribute(TiledMapConsts::tileheight);
    auto backgroundColor = node.attribute(TiledMapConsts::backgroundcolor);
    auto hexSideLength = node.attribute(TiledMapConsts::hexsidelength);
    auto staggerAxis = node.attribute(TiledMapConsts::staggeraxis);
    auto staggerIndex = node.attribute(TiledMapConsts::staggerindex);

    Orientation orientationVar = Orientation::ORTOGNAL;
    std::string orientationVal = orientation.as_string();
    if (orientationVal.compare("isometric") == 0)
    {
        orientationVar = Orientation::ISOMETRIC;
    }
    else if (orientationVal.compare("staggered") == 0)
    {
        orientationVar = Orientation::STAGGERED;
    }
    else if (orientationVal.compare("hexagonal") == 0)
    {
        orientationVar = Orientation::HEXAGONAL;
    }

    RenderOrder renderorder = RenderOrder::RIGHT_DOWN;
    std::string renderorderVal = orientation.as_string();
    if (renderorderVal.compare("right-up") == 0)
    {
        renderorder = RenderOrder::RIGHT_UP;
    }
    else if (renderorderVal.compare("left-down") == 0)
    {
        renderorder = RenderOrder::LEFT_DOWN;
    }
    else if (renderorderVal.compare("left-up") == 0)
    {
        renderorder = RenderOrder::LEFT_UP;
    }

    return new TiledMap(
        version.value(),
        tiledVersion.value(),
        orientationVar,
        renderorder,
        width.as_int(),
        height.as_int(),
        tileWidth.as_int(),
        tileHeight.as_int(),
        backgroundColor.empty() ? Color() : Color(std::string(backgroundColor.as_string())),
        hexSideLength.empty() ? -1 : hexSideLength.as_int(),
        staggerAxis.empty() ? "" : std::string(staggerAxis.as_string()),
        staggerIndex.empty() ? "" : std::string(staggerIndex.as_string())
    );
}
