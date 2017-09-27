#include "TiledLayerComponent.h"


TiledLayerComponent::TiledLayerComponent(int width, int height, int ** layerTiles, int layerOrder) :
    Component("TiledLayerComponent"),
    _width(width),
    _height(height),
    _layerTiles(layerTiles),
    _layerOrder(layerOrder)
{
}

TiledLayerComponent::~TiledLayerComponent()
{
}

void TiledLayerComponent::initialize(bool force)
{
}

void TiledLayerComponent::terminate()
{
    for (size_t row = 0; row < (size_t)this->_height; row++)
    {
        delete [] this->_layerTiles[row];
    }

    delete [] this->_layerTiles;
}
