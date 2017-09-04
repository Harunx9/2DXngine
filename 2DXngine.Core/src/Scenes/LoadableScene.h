#pragma once
#include "Scene.h"
#include "SceneLoader.h"

class LoadableScene : public Scene
{
public:
    LoadableScene(SpriteBatch* batch, SceneLoader* loader);
    ~LoadableScene();

    // Inherited via Scene
    virtual void createScene() override;
protected:
    SceneLoader* _loader;
};

