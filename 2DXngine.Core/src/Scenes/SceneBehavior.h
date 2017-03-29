#pragma once
#include "Scene.h"

class SceneBehavior
{
public:
    SceneBehavior(Scene* const scene);
    virtual ~SceneBehavior();

    virtual void update(float deltaTime) = 0;
    virtual void resolveDependencies() = 0;

    void activate();
    void deactivate();
    bool get_isActive() const;

private:
    Scene* _scene;
    bool _isActive;
};

