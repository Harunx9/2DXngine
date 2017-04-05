#include "Scene.h"
#include "../Graphics/Renderer.h"
#include "../ComponentModel/GameObjectManager.h"
#include "SceneManager.h"
#include "SceneRenderSystem.h"
#include "SceneUpdateSystem.h"
#include "../Services/ServiceLocator.h"

Scene::Scene(const char * name):
    _name(name)
{
    this->_renderer = new Renderer();
    this->_gameObjectManager = new GameObjectManager(this);
    this->_sceneManager = ServiceLocator::get<SceneManager>("SceneManager");
    this->_renderSystem = new SceneRenderSystem(this);
    this->_updateSystem = new SceneUpdateSystem(this);
}

Scene::Scene(const Scene * other)
{
    this->_renderer = other->_renderer;
    this->_gameObjectManager = other->_gameObjectManager;
    this->_sceneManager = other->_sceneManager;
    this->_renderSystem = other->_renderSystem;
    this->_updateSystem = other->_updateSystem;
}


Scene::~Scene()
{
    delete _renderer;
    delete _gameObjectManager;
    delete _renderSystem;
    delete _updateSystem;
}

void Scene::initialize()
{
    this->_gameObjectManager->initialize();
    this->_renderSystem->initialize();
    this->_updateSystem->initialize();
    this->_sceneBehaviorManager.initialize();
}

void Scene::terminate()
{
    this->_gameObjectManager->terminate();
    this->_renderSystem->terminate();
    this->_updateSystem->terminate();
    this->_sceneBehaviorManager.terminate();
}

void Scene::update(float deltaTime)
{
    this->_sceneBehaviorManager.preUpdate(deltaTime);

    this->_updateSystem->update(deltaTime);

    this->_sceneBehaviorManager.postUpdate(deltaTime);
}

void Scene::draw(float deltaTime)
{
    this->_renderSystem->drawGameObjects(deltaTime);
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
