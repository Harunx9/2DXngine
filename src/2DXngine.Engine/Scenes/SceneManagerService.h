#pragma once
#include "../Services/Service.h"
#include "../Utils/Macros/PropertyMacro.h"
class Scene;

class SceneManagerService : public Service
{
public:
    SceneManagerService();
    ~SceneManagerService();

    virtual void initialize() override;
    virtual void terminate() override;

    void updateCurrentScene(float deltaTime);
    void drawCurrentScene(float deltaTime);
    void startWith(Scene* firstScene);
    void to(Scene* nextScene);

    READONLY_PROPERTY(bool, isStarted)
private:
    Scene* _currentScene;
};

