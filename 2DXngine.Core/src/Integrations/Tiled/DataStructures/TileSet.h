#pragma once
#include <string>
#include "../../../Utils/Macros/PropertyMacro.h"
#include "ImageLayer.h"

struct TileOffset { int x; int y; };

class TileSet
{
public:
    TileSet() {}
    TileSet(int firstGid,
        std::string source):
        _firstGid(firstGid),
        _source(source)
    {
    }

    TileSet(int firstGid,
        std::string name,
        int tileWidth,
        int tileHeight,
        int spacing,
        int margin,
        int tileCount,
        int columns) :
        _firstGid(firstGid),
        _name(name),
        _tileWidth(tileWidth),
        _tileHeight(tileHeight),
        _spacing(spacing),
        _margin(margin),
        _tileCount(tileCount),
        _columns(columns)
    {
    }

    ~TileSet()
    {
    }

    READONLY_PROPERTY(int, firstGid)
    READONLY_PROPERTY(std::string, source)
    READONLY_PROPERTY(std::string, name)
    READONLY_PROPERTY(int, tileWidth)
    READONLY_PROPERTY(int, tileHeight)
    READONLY_PROPERTY(int, spacing)
    READONLY_PROPERTY(int, margin)
    READONLY_PROPERTY(int, tileCount)
    READONLY_PROPERTY(int, columns)
    PROPERTY(TileOffset, offset)
    PROPERTY(TmxImage, image)
};
