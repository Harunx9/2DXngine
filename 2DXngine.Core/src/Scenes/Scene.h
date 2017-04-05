#pragma once
#include <string>
#include "SceneBehaviorManager.h"
class Renderer;
class GameObjectManager;
class SceneManager;
class SceneRenderSystem;
class SceneUpdateSystem;

class Scene
{
public:
    Scene(const char * name = "");
    Scene(const Scene* other);
    virtual ~Scene();

    virtual void createScene() = 0;

    void initialize();
    void terminate();

    void update(float deltaTime);
    void draw(float deltaTime);

    Renderer* get_renderer() const;
    GameObjectManager * get_gameObjectManager() const;
    SceneManager * get_sceneManager() const;
    const char * get_name() const;

protected:
    Renderer * _renderer;
    GameObjectManager * _gameObjectManager;
    SceneManager * _sceneManager;
    SceneRenderSystem * _renderSystem;
    SceneUpdateSystem * _updateSystem;
    SceneBehaviorManager _sceneBehaviorManager;
    std::string _name;
};

