#include "SceneManagerService.h"
#include "Scene.h"

SceneManagerService::SceneManagerService() :Service("SceneManagerService"),
    _isStarted(false)
{
}

SceneManagerService::~SceneManagerService()
{
    this->baseTerminate();
}

void SceneManagerService::initialize()
{

}

void SceneManagerService::terminate()
{
    delete this->_currentScene;
    this->_currentScene = nullptr;
} 

void SceneManagerService::updateCurrentScene(float deltaTime)
{
    if (this->_currentScene->get_isInitialized() == false ||
        this->_currentScene->get_isTerminated()) return;
    
    this->_currentScene->update(deltaTime);
}

void SceneManagerService::drawCurrentScene(float deltaTime)
{
    if (this->_currentScene->get_isInitialized() == false ||
        this->_currentScene->get_isTerminated()) return;

    this->_currentScene->draw(deltaTime);
}

void SceneManagerService::StartWith(Scene* firstScene)
{
    if (this->_isStarted) return;
    if (firstScene->get_isInitialized()) return;

    firstScene->initialize();

    this->_currentScene = firstScene;

    this->_isStarted = true;
}

void SceneManagerService::To(Scene* nextScene)
{
    if (this->_isStarted == false) return;
    if (nextScene->get_isInitialized()) return;

    nextScene->initialize();

    this->_currentScene = nextScene;
}