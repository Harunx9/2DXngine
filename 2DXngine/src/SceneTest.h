#pragma once
#include <Scenes\Scene.h>
class SceneTest : public Scene
{
public:
    SceneTest(SpriteBatch* batch);
    ~SceneTest();

    virtual void createScene();
};
