#include "SceneRenderSystem.h"



SceneRenderSystem::SceneRenderSystem(Scene *const scene) :
    _scene(scene)
{
}


SceneRenderSystem::~SceneRenderSystem()
{
}

void SceneRenderSystem::initialize()
{
    auto gameObjectManager = this
        ->_scene
        ->get_gameObjectManager();


}

void SceneRenderSystem::terminate()
{
}

void SceneRenderSystem::drawGameObjects(float deltaTime)
{
    for (auto& drawable : this->_drawables)
    {
        if (drawable->get_isVisible())
            drawable->draw(this->_scene->get_renderer(), deltaTime);
    }
}
