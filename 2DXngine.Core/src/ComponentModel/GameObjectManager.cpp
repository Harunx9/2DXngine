#include "GameObjectManager.h"



GameObjectManager::GameObjectManager(Scene* scene):
    _scene(scene)
{

}


GameObjectManager::~GameObjectManager()
{
}

Scene * GameObjectManager::get_scene() const
{
    return this->_scene;
}

void GameObjectManager::initialize()
{
}

void GameObjectManager::terminate()
{
}

void GameObjectManager::addGameObject(GameObject * gameObject)
{

}

GameObject * GameObjectManager::findObject(const char * name)
{
    return nullptr;
}

gameobject_list GameObjectManager::findGameObjecsByTag(const char * tag)
{
    return gameobject_list();
}

void GameObjectManager::removeGameObject(const char * name)
{
}

void GameObjectManager::cacheAllComponents()
{
    if (this->_componentsCache.empty() == false)
    {
        this->_componentsCache.clear();
    }

    for (auto& gameObject : this->_gameObjects)
    {

    }
}
