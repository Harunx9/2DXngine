#pragma once
#include <vector>
#include "../../ComponentModel/GameObject.h"
#include "DataStructures/TiledMap.h"

class GameObjectFactory
{
public:
    GameObjectFactory(std::string name): _name(name) {};
    virtual ~GameObjectFactory() {};

    virtual std::vector<GameObject* > map(TiledMap* map) = 0;
    READONLY_PROPERTY(std::string, name)
};
