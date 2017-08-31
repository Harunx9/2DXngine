#include "SceneRenderSystem.h"
#include "../ComponentModel/GameObjectFilterFunctions.h"
#include "../ComponentModel/GameObjectManager.h"
#include "../ComponentModel/DrawableComponent.h"

SceneRenderSystem::SceneRenderSystem(Scene *const scene) :
    _scene(scene)
{
}

SceneRenderSystem::~SceneRenderSystem()
{
    this->_scene = nullptr;
}

void SceneRenderSystem::initialize()
{
    auto gameObjectManager = this
        ->_scene
        ->get_gameObjectManager();

    auto gameObjects = gameObjectManager->get_gameObjects();

    for (auto gameObject : gameObjects)
    {
        auto drawablesFromGameObject = getAllComponentFromGameObjectAndChildren<DrawableComponent>(gameObject, false);

        this->_drawables.insert(
            _drawables.end(),
            drawablesFromGameObject.begin(),
            drawablesFromGameObject.end());
    }
}

void SceneRenderSystem::terminate()
{
    this->_drawables.clear();
}

void SceneRenderSystem::drawGameObjects(float deltaTime)
{
    for (auto& drawable : this->_drawables)
    {
        if (drawable->get_isVisible())
        {
           // this->_scene->get_renderer()->set_batchTarget(&drawable->get_layer());

            drawable->draw(this->_scene->get_renderer(), this->_scene->get_camera(), deltaTime);
            
           // this->_scene->get_renderer()->reset_batchTarget();
        }
    }
}
