#include "TiledMapLayerOrtoDrawable.h"
#include "../../../ComponentModel/GameObjectManager.h"
#include <algorithm>
#include "../../../Graphics/Camera.h"

TiledMapLayerOrtoDrawable::TiledMapLayerOrtoDrawable() :
    TiledMapLayerOrtoDrawable(TextureWrap::CLAMP_TO_EDGE, TextureFilter::POINT_FILTER)
{
}

TiledMapLayerOrtoDrawable::TiledMapLayerOrtoDrawable(TextureWrap wrap, TextureFilter filter) :
    DrawableComponent(DefaultLayers::GAMEPLAY_LAYER, "TiledMapLayerOrtoDrawable"),
    _wrap(wrap),
    _filter(filter),
    _isCached(false)
{
}

TiledMapLayerOrtoDrawable::~TiledMapLayerOrtoDrawable()
{
}

void TiledMapLayerOrtoDrawable::resolveDependencies(bool force)
{
    this->_tansform =
        this
        ->_owner
        ->findFirstComponentOfType<Transform>();

    this->_layer =
        this
        ->_owner
        ->findFirstComponentOfType<TiledLayerComponent>();

    this->_tilesets =
        this
        ->_owner
        ->get_manager()
        ->findObject("tilesets")
        ->findAllComponentsOfType<TileSetComponent>();
}

void TiledMapLayerOrtoDrawable::initialize(bool force)
{
}

void TiledMapLayerOrtoDrawable::terminate()
{
    this->_tilesets.clear();
    this->_layer = nullptr;
    this->_tansform = nullptr;
}

void TiledMapLayerOrtoDrawable::draw(Renderer * renderer, Camera * camera, float deltaTime)
{
    if (this->_isCached == false)
    {
        this->cacheTilesToDraw();
    }
    auto batch = renderer->get_batch();

    batch->begin(nullptr, this->_wrap, this->_filter, camera->get_viewMatrix());

    for (size_t tile = 0; tile < (size_t)this->_tilesCount; ++tile)
    {
        auto drawItem = this->_tilesToDraw[tile];
        if (drawItem.state != TileToDrawState::EMPTY)
            batch->draw(
                drawItem.tex->get_texture(),
                drawItem.pos,
                &drawItem.rect,
                Colors::white,
                this->_layer->get_layerOrder() * 0.01f);
    }

    batch->end();
}

void TiledMapLayerOrtoDrawable::cacheTilesToDraw()
{
    this->_tilesToDraw = new TileToDraw[this->_layer->get_height() * this->_layer->get_width()];
    this->_tilesCount = this->_layer->get_height() * this->_layer->get_width();
    int index = 0;

    for (size_t row = 0; row < (size_t)this->_layer->get_height(); ++row)
    {
        for (size_t col = 0; col < (size_t)this->_layer->get_width(); ++col)
        {
            int tileId = this->_layer->get_tile(col, row);

            auto tilesetIter = std::find_if(
                this->_tilesets.begin(),
                this->_tilesets.end(),
                [&](TileSetComponent* c) { return c->get_isTileInTileset(tileId); });

            if (tilesetIter != std::end(this->_tilesets))
            {
                auto tileset = *tilesetIter;
                TileToDraw tileToDraw =
                {
                    glm::ivec2(col * tileset->get_tileWidth(), row * tileset->get_tileHeight()),
                    tileset->get_tileCoords(tileId),
                    tileset->get_sprite(),
                    TileToDrawState::FILLED
                };

                this->_tilesToDraw[index] = tileToDraw;
            }

            ++index;
        }
    }

    this->_isCached = true;
}

void TiledMapLayerOrtoDrawable::clearCache()
{

    this->_isCached = false;
}
