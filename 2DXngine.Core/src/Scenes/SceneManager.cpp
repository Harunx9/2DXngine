#include "SceneManager.h"
#include "Scene.h"


SceneManager::SceneManager(): Service("SceneManager")
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::initialize()
{
}

void SceneManager::terminate()
{
}

void SceneManager::To(Scene * nextScene)
{
    if (nextScene->get_isInitialized()) return;
}
