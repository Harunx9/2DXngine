#pragma once
#include "../GameObjectFactory.h"
class TileLayersFactory : public GameObjectFactory
{
public:
    TileLayersFactory();
    ~TileLayersFactory();

    virtual std::vector<GameObject*> map(TiledMap * map) override;

};

