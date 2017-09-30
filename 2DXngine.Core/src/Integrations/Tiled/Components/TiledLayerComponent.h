#pragma once
#include "../../../ComponentModel/Component.h"

class TiledLayerComponent : public Component
{
public:
    ADD_TYPE_META_INFO()
        TiledLayerComponent(std::string nameLayer, int width, int height, int ** layerTiles, int layerOrder);
    ~TiledLayerComponent();

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;

    int get_tile(int x, int y) const
    {
        return this->_layerTiles[y][x];
    }

    READONLY_PROPERTY(int, width)
    READONLY_PROPERTY(int, height)
    READONLY_PROPERTY(int, layerOrder)
    READONLY_PROPERTY(std::string, nameLayer)
protected:
    int ** _layerTiles;
};

