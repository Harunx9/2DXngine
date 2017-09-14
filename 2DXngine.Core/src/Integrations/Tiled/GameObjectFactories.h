#pragma once
#include <vector>
#include <algorithm>
#include "../../ComponentModel/GameObject.h"
#include "DataStructures/TiledMap.h"
#include "GameObjectFactory.h"

class GameObjectFactories
{
public:
    GameObjectFactories();
    ~GameObjectFactories();

    std::vector<GameObject*> create(TiledMap * map);

    void registerFactory(GameObjectFactory* factory)
    {
        this->_factories.push_back(factory);
    }

    void removeFactory(std::string name)
    {
        std::remove_if(
            this->_factories.begin(),
            this->_factories.end(),
            [=](GameObjectFactory* f) { return f->get_name().compare(name) == 0; }
        );
    }
private:
    std::vector<GameObjectFactory*> _factories;
};
