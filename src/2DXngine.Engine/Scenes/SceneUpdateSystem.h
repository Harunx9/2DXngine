#pragma once
#include <vector>
#include "Scene.h"
#include "../ComponentModel/UpdateableComponent.h"

typedef std::vector<UpdateableComponent*> updateable_list;

class SceneUpdateSystem
{
public:
    SceneUpdateSystem(Scene *const scene);
    ~SceneUpdateSystem();

    void initialize();
    void terminate();

    void update(float deltaTime);
private:
    Scene * _scene;
    updateable_list _updateables;
};

