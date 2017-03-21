#pragma once
#include <string>
#include "../Graphics/Renderer.h"
#include "../ComponentModel/GameObjectManager.h"
#include "SceneManager.h"

class Scene
{
public:
    Scene(const char * name="");
    Scene(const Scene* other);
    virtual ~Scene();

    virtual void createScene() = 0;

    void initialize();
    void terminate();
    void update(float deltaTime);
    void draw(float deltaTime);

protected:
    Renderer* _renderer;
    GameObjectManager* _gameObjectManager;
    SceneManager* _sceneManager;
    std::string _name;
};

