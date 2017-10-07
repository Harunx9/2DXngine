#pragma once
#include "../GameObjectFactory.h"
class TilesetsFactory : public GameObjectFactory
{
public:
    TilesetsFactory();
    ~TilesetsFactory();

    // Inherited via GameObjectFactory
    virtual std::vector<GameObject*> map(TiledMap * map) override;
};

