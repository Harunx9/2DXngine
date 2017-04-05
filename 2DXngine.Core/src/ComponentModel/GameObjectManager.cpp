#include "GameObjectManager.h"
#include <assert.h>
#include <algorithm>

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
    for (auto& gameObject : this->_gameObjects)
    {
        gameObject->initialize();
    }
}

void GameObjectManager::terminate()
{
    for (auto& gameObject : this->_gameObjects)
    {
        gameObject->terminate();
    }
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
    this->_gameObjects.erase(
        std::remove_if(
            this->_gameObjects.begin(),
            this->_gameObjects.end(),
            [name](GameObject* go) { return std::strcmp(go->get_name(), name) == 0; }),
        this->_gameObjects.end());
}

gameobject_list GameObjectManager::get_gameObjects() const
{
    return this->_gameObjects;
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
