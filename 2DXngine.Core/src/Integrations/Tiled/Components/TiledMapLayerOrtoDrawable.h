#pragma once
#include "../../../ComponentModel/DrawableComponent.h"
#include "../../../Components/Graphics/Transform.h"
#include "../../../Components/Graphics/SpriteComponent.h"
#include "TiledLayerComponent.h"
#include "TileSetComponent.h"

class TiledMapLayerOrtoDrawable : public DrawableComponent
{
public:
    ADD_TYPE_META_INFO()
        TiledMapLayerOrtoDrawable();
    TiledMapLayerOrtoDrawable(TextureWrap wrap, TextureFilter filter);
    ~TiledMapLayerOrtoDrawable();

    void clearCache();
    virtual void resolveDependencies(bool force = false) override;
    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void draw(Renderer * renderer, Camera * camera, float deltaTime) override;
private:
    enum class TileToDrawState
    {
        EMPTY,
        FILLED
    };

    struct TileToDraw {
        glm::ivec2 pos;
        RectangleI rect;
        SpriteComponent* tex;
        TileToDrawState state = TileToDrawState::EMPTY;
    };

    void cacheTilesToDraw();

    Transform* _tansform;
    TiledLayerComponent* _layer;
    std::vector<TileSetComponent*> _tilesets;
    TileToDraw* _tilesToDraw;
    int _tilesCount;
    bool _isCached;
    TextureWrap _wrap;
    TextureFilter _filter;
};

