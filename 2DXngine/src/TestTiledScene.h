#pragma once
#include <Scenes\LoadableScene.h>
class TestTiledScene: public LoadableScene
{
public:
    TestTiledScene(SpriteBatch* batch, SceneLoader* loader);
    ~TestTiledScene();

    virtual void setup() override;
};

