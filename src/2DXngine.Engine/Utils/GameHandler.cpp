#include "GameHandler.h"
#include "../Scenes/SceneManagerService.h"
#include "../Services/ServiceLocator.h"
#include "../Graphics/SpriteBatch.h"

GameHandler::GameHandler()
{
}

GameHandler::~GameHandler()
{
    delete this->_device;
}

EmptyGameHandler::EmptyGameHandler()
{
}

EmptyGameHandler::~EmptyGameHandler()
{
}

void EmptyGameHandler::initialize()
{
}

void EmptyGameHandler::update(float deltaTime)
{
}

void EmptyGameHandler::draw(float deltaTime)
{
}

GameHandlerWithScenes::~GameHandlerWithScenes()
{
    delete this->_sceneManager;
}

void GameHandlerWithScenes::initialize()
{
    this->_sceneManager = ServiceLocator::get<SceneManagerService>("SceneManagerService");
}

void GameHandlerWithScenes::update(float deltaTime)
{
    this->_sceneManager->updateCurrentScene(deltaTime);
}

void GameHandlerWithScenes::draw(float deltaTime)
{
    this->_sceneManager->drawCurrentScene(deltaTime);
}

Game2DWithScenesHandler::~Game2DWithScenesHandler()
{
    delete this->_batch;
}

void Game2DWithScenesHandler::initialize()
{
    GameHandlerWithScenes::initialize();
    this->_batch = new SpriteBatch(this->_device);
    this->_batch->initialize();
}
