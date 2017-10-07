#pragma once
#include "../../../ComponentModel/Component.h"
#include "../../../Utils/Math/RectangleI.h"
#include "../../../Components/Graphics/SpriteComponent.h"

class TileSetComponent : public Component
{
public:
    ADD_TYPE_META_INFO()
        TileSetComponent(
            int firtsId,
            int tileWidth,
            int tileHeight,
            int spaceing,
            int margin,
            int tileCount,
            int collumns,
            int imageWidth,
            int imageHeight,
            std::string spritePath
        );
    ~TileSetComponent();

    RectangleI get_tileCoords(int tileId);
    bool get_isTileInTileset(int tileId);
    SpriteComponent* get_sprite()
    {
        return this->_sprite;
    }

    READONLY_PROPERTY(std::string, spritePath)
    READONLY_PROPERTY(std::string, fileName)
    READONLY_PROPERTY(int, tileWidth)
    READONLY_PROPERTY(int, tileHeight)

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void resolveDependencies(bool force = false) override;
private:
    void cacheRects();

    int _firtsId;
    int _spaceing;
    int _margin;
    int _tileCount;
    int _collumns;
    int _imageWidth;
    int _imageHeight;
    RectangleI* _cachedRects;
    SpriteComponent * _sprite;
};

