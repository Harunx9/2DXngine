#pragma once
#include "../Scenes/Scene.h"
#include "GameObject.h"

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

    template<typename TComponent>
    components_list findComponents(bool exactType = true);

    template<typename TComponent>
    TComponent* findFistComponent(bool exactType = true);

private:
    void cacheAllComponents();
    Scene* _scene;
    gameobject_list _gameObjects;
    components_list _componentsCache;
};

template<typename TComponent>
inline components_list GameObjectManager::findComponents(bool exactType)
{
    return components_list();
}

template<typename TComponent>
inline TComponent * GameObjectManager::findFistComponent(bool exactType)
{
    return NULL;
}
