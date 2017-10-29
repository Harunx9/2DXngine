#pragma once
#include "../../ComponentModel/Component.h"
#include <vector>

struct NavMeshConfig
{
    int layerNumber;
    size_t navMeshWidth;
    size_t navMeshHeight;
    float navGridTileWidth;
    float navGridTileHeight;
};

class NavMeshLayerComponent : public Component
{
public:
    ADD_TYPE_META_INFO()
    NavMeshLayerComponent(NavMeshConfig cfg);
    ~NavMeshLayerComponent();

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void generate() = 0;

    int get_layerNumber()
    {
        return this->_cfg.layerNumber;
    }

    READONLY_PROPERTY(bool **, mesh)
    READONLY_PROPERTY(NavMeshConfig, cfg)
   
    bool isBlocked(int x, int y)
    {
        return this->_mesh[y][x];
    }
};


class NavMeshComponent : public Component
{
public:
    ADD_TYPE_META_INFO()
    NavMeshComponent();
    ~NavMeshComponent();

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void resolveDependencies(bool force = false) override;

    bool isBlocked(int layer, int x, int y) const
    {
        return this->_layers[layer]->isBlocked(x, y);
    }

    NavMeshLayerComponent* get_layer(int layer) const
    {
        return this->_layers[layer];
    }

private:
    std::vector<NavMeshLayerComponent*> _layers;
};

