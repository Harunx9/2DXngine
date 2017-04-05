#include "SceneUpdateSystem.h"
#include "../ComponentModel/GameObjectFilterFunctions.h"
#include "../ComponentModel/UpdateableComponent.h"
#include "../ComponentModel/GameObjectManager.h"


SceneUpdateSystem::SceneUpdateSystem(Scene *const scene) :
    _scene(scene)
{
}


SceneUpdateSystem::~SceneUpdateSystem()
{
    this->_scene = nullptr;
}

void SceneUpdateSystem::initialize()
{
    auto gameObjectManager = this
        ->_scene
        ->get_gameObjectManager();

    auto gameObjects = gameObjectManager->get_gameObjects();

    for (auto gameObject : gameObjects)
    {
        auto updateablesFromGameObject = getAllComponentFromGameObjectAndChildren<UpdateableComponent>(gameObject, false);

        this->_updateables.insert(
            _updateables.end(),
            updateablesFromGameObject.begin(),
            updateablesFromGameObject.end());
    }
}

void SceneUpdateSystem::terminate()
{
    this->_updateables.clear();
}

void SceneUpdateSystem::update(float deltaTime)
{
    for (auto& updateable : this->_updateables)
    {
        if (updateable->get_isActive())
            updateable->update(deltaTime);
    }
}
