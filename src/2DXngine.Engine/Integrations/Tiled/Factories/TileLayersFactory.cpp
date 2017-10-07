#include "TileLayersFactory.h"
#include "../../../Components/Graphics/Transform.h"
#include "../Components/TiledLayerComponent.h"
#include "../Components/TiledMapLayerOrtoDrawable.h"

TileLayersFactory::TileLayersFactory() : GameObjectFactory("TileLayersFactory")
{
}


TileLayersFactory::~TileLayersFactory()
{
}

std::vector<GameObject*> TileLayersFactory::map(TiledMap * map)
{
    std::vector<GameObject*> obj;

    auto tileLayers = map->get_AllTileLayers();
    int order = 0;
    for (auto& tileLayer : tileLayers)
    {
        auto name = tileLayer.get_name();
        auto go = new GameObject(name.c_str());

        auto transform = new Transform();
        transform->set_position(glm::vec2(tileLayer.get_x(), tileLayer.get_y()));

        go->addComponent(transform)
            ->addComponent(new TiledLayerComponent(
                tileLayer.get_name(),
                tileLayer.get_width(),
                tileLayer.get_height(),
                tileLayer.to2DArray(),
                order)
            )
            ->addComponent(new TiledMapLayerOrtoDrawable());

        obj.push_back(go);

        ++order;
    }


    return obj;
}
