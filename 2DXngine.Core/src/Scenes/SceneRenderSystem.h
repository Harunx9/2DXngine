#pragma once
#include <vector>
#include "Scene.h"
#include "../ComponentModel/DrawableComponent.h"

typedef std::vector<DrawableComponent*> drawable_list;

class SceneRenderSystem
{
public:
    SceneRenderSystem(Scene *const scene);
    ~SceneRenderSystem();

    void initialize();
    void terminate();

    void drawGameObjects(float deltaTime);

private:
    drawable_list _drawables;
    Scene* _scene;
};

