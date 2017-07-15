#pragma once
#include <string>
#include "SceneBehaviorManager.h"
#include "../Utils/Macros/PropertyMacro.h"
class Camera;
class Renderer;
class SpriteBatch;
class GameObjectManager;
class SceneManagerService;
class SceneRenderSystem;
class SceneUpdateSystem;

class Scene
{
public:
    Scene(SpriteBatch* batch, std::string name = "");
    Scene(const Scene* other);
    virtual ~Scene();

    void initialize();
    void terminate();

    void update(float deltaTime);
    void draw(float deltaTime);

    READONLY_PROPERTY(bool, isInitialized)
    READONLY_PROPERTY(bool, isTerminated)
    READONLY_PROPERTY(Renderer *, renderer)
    READONLY_PROPERTY(GameObjectManager *, gameObjectManager)
    READONLY_PROPERTY(SceneManagerService *, sceneManager)
    READONLY_PROPERTY(std::string, name)
    READONLY_PROPERTY(Camera*, camera)
protected:
    virtual void createScene() = 0;
    SceneRenderSystem * _renderSystem;
    SceneUpdateSystem * _updateSystem;
    SceneBehaviorManager _sceneBehaviorManager;
};

