#include <algorithm>

#include "NavMeshComponent.h"
#include "../../ComponentModel/GameObject.h"

NavMeshLayerComponent::NavMeshLayerComponent(NavMeshConfig cfg):
    Component("NavMeshLayerComponent"),
    _cfg(cfg)
{
}

NavMeshLayerComponent::~NavMeshLayerComponent()
{
    for (size_t i = 0; i < this->_cfg.navMeshHeight; i++)
    {
        delete this->_mesh[i];
    }

    delete this->_mesh;
}

void NavMeshLayerComponent::initialize(bool force)
{
    this->generate();
}

void NavMeshLayerComponent::terminate()
{
}


NavMeshComponent::NavMeshComponent()
{
}

NavMeshComponent::~NavMeshComponent()
{
    if (this->_layers.size() > 0)
    {
        for (auto & layer : this->_layers)
        {
            delete layer;
        }
        this->_layers.clear();
    }
}

void NavMeshComponent::initialize(bool force)
{
}

void NavMeshComponent::terminate()
{
}

void NavMeshComponent::resolveDependencies(bool force)
{
    this->_layers = this->_owner->findAllComponentsOfType<NavMeshLayerComponent>(false);
    if (this->_layers.size() > 0)
    {
        std::sort(this->_layers.begin(), this->_layers.end(),
            [&](NavMeshLayerComponent* a, NavMeshLayerComponent* b)
        { return a->get_layerNumber() < b->get_layerNumber(); });
    }
}
