#include "Scene.h"
#include "../Graphics/Renderer.h"
#include "../ComponentModel/GameObjectManager.h"
#include "SceneManager.h"
#include "SceneBehaviorManager.h"
#include "SceneRenderSystem.h"
#include "SceneUpdateSystem.h"

Scene::Scene(const char * name):
    _name(name)
{
}

Scene::Scene(const Scene * other)
{
}


Scene::~Scene()
{
}

void Scene::initialize()
{
}

void Scene::terminate()
{
}

void Scene::update(float deltaTime)
{
    
}

void Scene::draw(float deltaTime)
{
}

Renderer * Scene::get_renderer() const
{
    return this->_renderer;
}

GameObjectManager * Scene::get_gameObjectManager() const
{
    return this->_gameObjectManager;
}

SceneManager * Scene::get_sceneManager() const
{
    return this->_sceneManager;
}

const char * Scene::get_name() const
{
    return this->_name.c_str();
}
