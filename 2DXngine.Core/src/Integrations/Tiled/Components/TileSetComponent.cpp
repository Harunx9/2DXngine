#include "TileSetComponent.h"
#include "../../../ComponentModel/GameObject.h"
#include <string>
TileSetComponent::TileSetComponent(
    int firtsId,
    int tileWidth, int tileHeight,
    int spaceing, int margin,
    int tileCount, int collumns,
    int imageWidth, int imageHeight, std::string spritePath) : Component("TileSetComponent"),
    _firtsId(firtsId),
    _tileWidth(tileWidth),
    _tileHeight(tileHeight),
    _spaceing(spaceing),
    _margin(margin),
    _tileCount(tileCount),
    _collumns(collumns),
    _imageWidth(imageWidth),
    _imageHeight(imageHeight),
    _spritePath(spritePath)
{
}

TileSetComponent::~TileSetComponent()
{
}

RectangleI TileSetComponent::get_tileCoords(int tileId)
{
    int realId = tileId - this->_firtsId;
    return this->_cachedRects[realId];
}

bool TileSetComponent::get_isTileInTileset(int tileId)
{
    return this->_firtsId <= tileId &&
        tileId <= this->_firtsId + this->_tileCount;
}

void TileSetComponent::initialize(bool force)
{
    this->cacheRects();
    this->_fileName = AssetPath::get_fileName(this->_spritePath);
}

void TileSetComponent::terminate()
{
    delete[] this->_cachedRects;
}

void TileSetComponent::resolveDependencies(bool force)
{
    this->_sprite = this->_owner
        ->findFirstComponentBy<SpriteComponent>(
            [&](SpriteComponent* c)
    { return  c->get_fileName().compare(this->_fileName) == 0; });
}

void TileSetComponent::cacheRects()
{
    this->_cachedRects = new RectangleI[this->_tileCount];

    int row = 0;
    int col = 0;
    int x = 0;
    int y = 0;

    for (size_t tileNum = 0; tileNum < (size_t)this->_tileCount; ++tileNum)
    {
        if (col >= this->_collumns)
        {
            ++row;
            col = 0;
        }

        x = col * this->_tileWidth;
        y = row * this->_tileHeight;

        this->_cachedRects[tileNum] = RectangleI(x, y, this->_tileWidth, this->_tileHeight);

        ++col;
    }
}
