#pragma once
#include "GameObject.h"

class Scene;

class GameObjectManager
{
public:
    GameObjectManager(Scene* scene);
    GameObjectManager(const GameObjectManager* scene) = delete;
    ~GameObjectManager();

    Scene* get_scene() const;
    
    void initialize();
    void terminate();

    void addGameObject(GameObject* gameObject);
    GameObject * findObject(const char* name);
    gameobject_list findGameObjecsByTag(const char* tag);
    void removeGameObject(const char* name);

private:
    bool gameObjectExist(const char* name);
    Scene* _scene;
    gameobject_list _gameObjects;
    components_list _componentsCache;
};
