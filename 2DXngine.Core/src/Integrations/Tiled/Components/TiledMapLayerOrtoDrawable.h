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
    ~TiledMapLayerOrtoDrawable();

    virtual void resolveDependencies(bool force = false) override;
    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void draw(Renderer * renderer, Camera * camera, float deltaTime) override;
public:
    struct TileToDraw {
        glm::vec2 pos;
        glm::vec2 size;
        RectangleI rect;
        Texture* tex;
    };

    void cacheTilesToDraw();

    Transform* _tansform;
    TiledLayerComponent* _layer;
    std::vector<TileSetComponent*> _tilesets;
    TileToDraw* _tilesToDraw;
    int _tilesCount;
};

