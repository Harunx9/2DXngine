#include "SceneUpdateSystem.h"



SceneUpdateSystem::SceneUpdateSystem(Scene *const scene) :
    _scene(scene)
{
}


SceneUpdateSystem::~SceneUpdateSystem()
{
}

void SceneUpdateSystem::initialize()
{

}

void SceneUpdateSystem::terminate()
{
}

void SceneUpdateSystem::update(float deltaTime)
{
    for (auto& updateable : this->_updateables)
    {
        if (updateable->get_isActive())
            updateable->update(deltaTime);
    }
}
