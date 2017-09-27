#include "TiledMapLayerOrtoDrawable.h"
#include "../../../ComponentModel/GameObjectManager.h"
#include <algorithm>


TiledMapLayerOrtoDrawable::TiledMapLayerOrtoDrawable() : DrawableComponent(DefaultLayers::GAMEPLAY_LAYER, "TiledMapLayerOrtoDrawable")
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
    this->cacheTilesToDraw();
}

void TiledMapLayerOrtoDrawable::terminate()
{
    this->_tilesets.clear();
    this->_layer = nullptr;
    this->_tansform = nullptr;
}

void TiledMapLayerOrtoDrawable::draw(Renderer * renderer, Camera * camera, float deltaTime)
{
    auto batch = renderer->get_batch();

    batch->begin();

    for (size_t tile = 0; tile < (size_t)this->_tilesCount; ++tile)
    {
        auto drawItem = this->_tilesToDraw[tile];
        batch->draw(drawItem.tex, drawItem.pos, &drawItem.rect, Colors::white, this->_layer->get_layerOrder() * 0.01f);
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

            auto tileset = *std::find_if(
                this->_tilesets.begin(),
                this->_tilesets.end(),
                [&](TileSetComponent* c) { return c->get_isTileInTileset(tileId); });

            if (tileset != nullptr)
            {
                TileToDraw tileToDraw =
                {
                    glm::vec2(col * tileset->get_tileWidth(), row * tileset->get_tileHeight()),
                    glm::vec2(tileset->get_tileWidth(), tileset->get_tileHeight()),
                    tileset->get_tileCoords(tileId),
                    tileset->get_tilesetTexture()
                };

                this->_tilesToDraw[index] = tileToDraw;
            }

            ++index;
        }
    }
}
