#include "TileMapParser.h"
#include "../DataStructures/TiledMap.h"


TileMapParser::TileMapParser()
{
}


TileMapParser::~TileMapParser()
{
}

TiledMap* TileMapParser::parse(pugi::xml_node & node)
{
    TiledMap* map = this->parseTiledMapAttributes(node);

    return map;
}

TiledMap* TileMapParser::parseTiledMapAttributes(pugi::xml_node & node)
{
    auto version = node.attribute("version");
    auto tiledVersion = node.attribute("tiledversion");
    auto orientation = node.attribute("orientation");
    auto renderOrder = node.attribute("renderorder");
    auto width = node.attribute("width");
    auto height = node.attribute("height");
    auto tileWidth = node.attribute("tilewidth");
    auto tileHeight = node.attribute("tileheight");
    auto backgroundColor = node.attribute("backgroundcolor");
    auto hexSideLength = node.attribute("hexsidelength");
    auto staggerAxis = node.attribute("staggeraxis");
    auto staggerIndex = node.attribute("staggerindex");

    Orientation orientationVar = ORTOGNAL;
    std::string orientationVal = orientation.as_string();
    if (orientationVal.compare("isometric") == 0)
    {
        orientationVar = ISOMETRIC;
    }
    else if (orientationVal.compare("staggered") == 0)
    {
        orientationVar = STAGGERED;
    }
    else if (orientationVal.compare("hexagonal") == 0)
    {
        orientationVar = HEXAGONAL;
    }

    RenderOrder renderorder = RIGHT_DOWN;
    std::string renderorderVal = orientation.as_string();
    if (renderorderVal.compare("right-up") == 0)
    {
        renderorder = RIGHT_UP;
    }
    else if (renderorderVal.compare("left-down") == 0)
    {
        renderorder = LEFT_DOWN;
    }
    else if (renderorderVal.compare("left-up") == 0)
    {
        renderorder = LEFT_UP;
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
        staggerAxis  .empty() ? "" : std::string(staggerAxis .as_string()),
        staggerIndex .empty() ? "" : std::string(staggerIndex.as_string())
    );
}
