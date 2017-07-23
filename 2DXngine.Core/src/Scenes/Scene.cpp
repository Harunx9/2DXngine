#include "Scene.h"
#include "../Graphics/Renderer.h"
#include "../ComponentModel/GameObjectManager.h"
#include "SceneManagerService.h"
#include "SceneRenderSystem.h"
#include "SceneUpdateSystem.h"
#include "../Services/ServiceLocator.h"

Scene::Scene(SpriteBatch * batch, std::string name) :
    _name(name),
    _isInitialized(false),
    _isTerminated(false)
{
    this->_renderer = new Renderer(batch);
    this->_gameObjectManager = new GameObjectManager(this);
    this->_sceneManager = ServiceLocator::get<SceneManagerService>("SceneManagerService");
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
    if (this->_isInitialized) return;

    this->createScene();
    this->_gameObjectManager->initialize();
    this->_renderSystem->initialize();
    this->_updateSystem->initialize();
    this->_sceneBehaviorManager.initialize();

    this->_isInitialized = true;
}

void Scene::terminate()
{
    if (this->_isTerminated) return;

    this->_gameObjectManager->terminate();
    this->_renderSystem->terminate();
    this->_updateSystem->terminate();
    this->_sceneBehaviorManager.terminate();

    this->_isTerminated = true;
}

void Scene::update(float deltaTime)
{
    this->_sceneBehaviorManager.preUpdate(deltaTime);

    this->_updateSystem->update(deltaTime);

    this->_sceneBehaviorManager.postUpdate(deltaTime);
}

void Scene::draw(float deltaTime)
{
    this->_renderer->get_graphics()->clear(Colors::black);
    this->_renderSystem->drawGameObjects(deltaTime);
    this->_renderer->get_graphics()->swapBuffers();
}

