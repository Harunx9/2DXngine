#include "LoadableScene.h"
#include "../ComponentModel/GameObjectManager.h"

LoadableScene::LoadableScene(SpriteBatch* batch, SceneLoader* loader) :
    Scene(batch),
    _loader(loader)
{
}

LoadableScene::~LoadableScene()
{
}

void LoadableScene::createScene()
{
    auto gameObjects = _loader->load();
    for (auto& obj : gameObjects)
    {
        this->get_gameObjectManager()->addGameObject(obj);
    }
}
