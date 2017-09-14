#include "GameObjectFactories.h"



GameObjectFactories::GameObjectFactories()
{
}


GameObjectFactories::~GameObjectFactories()
{
}

std::vector<GameObject*> GameObjectFactories::create(TiledMap * map)
{
    std::vector<GameObject*> objects;

    for (auto& factory : this->_factories)
    {
        auto mappedObjects = factory->map(map);
        objects.insert(objects.end(), mappedObjects.begin(), mappedObjects.end());
    }

    return objects;
}
