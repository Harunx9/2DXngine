#pragma once
#include <Scenes\Scene.h>
class TestScene : public Scene
{
public:
    TestScene() : Scene(new SpriteBatch(new GraphicDevice()), "Test") {}
    ~TestScene() {}

    virtual void createScene() override {}
};

