#include "GameObjectManager.h"
#include <assert.h>


GameObjectManager::GameObjectManager(Scene* scene) :
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
    assert(this->gameObjectExist(gameObject->get_name()) == false);

    this->_gameObjects.push_back(gameObject);
}

GameObject * GameObjectManager::findObject(const char * name)
{
    for (auto& gameObject : this->_gameObjects)
    {
        if (std::strcmp(gameObject->get_name(), name) == 0)
        {
            return gameObject;
        }
    }

    return nullptr;
}

gameobject_list GameObjectManager::findGameObjecsByTag(const char * tag)
{
    gameobject_list list;

    for (auto& gameObject : this->_gameObjects)
    {
        if (std::strcmp(gameObject->get_tag(), tag) == 0)
        {
            list.push_back(gameObject);
        }
    }

    return list;
}

void GameObjectManager::removeGameObject(const char * name)
{
}

bool GameObjectManager::gameObjectExist(const char* name)
{
    for (auto& gameObject : this->_gameObjects)
    {
        if (std::strcmp(gameObject->get_name(), name) == 0)
        {
            return true;
        }
    }
    return false;
}

void GameObjectManager::cacheAllComponents()
{
    if (this->_componentsCache.empty() == false)
    {
        this->_componentsCache.clear();
    }

    for (auto& gameObject : this->_gameObjects)
    {
        this->_componentsCache.insert(
            this->_componentsCache.end(),
            gameObject->get_components()->begin(),
            gameObject->get_components()->end());
    }
}

void GameObjectManager::cacheAllGameObjects()
{

}
