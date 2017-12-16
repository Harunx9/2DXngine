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
    int minWeight;
    int impasibleWeight;
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

    bool is_blocked(int x, int y)
    {
        return this->_mesh[y][x] == this->_cfg.impasibleWeight;
    }

    bool is_outOfBounds(int x, int y)
    {
        return x < 0 || y < 0 || x > this->_cfg.navMeshWidth - 1 || y > this->_cfg.navMeshHeight - 1;
    }

    READONLY_PROPERTY(int **, mesh)
    READONLY_PROPERTY(NavMeshConfig, cfg)
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

    NavMeshLayerComponent* get_layer(int layer) const
    {
        return this->_layers[layer];
    }

private:
    std::vector<NavMeshLayerComponent*> _layers;
};

