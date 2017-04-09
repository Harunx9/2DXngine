#pragma once
#include "../Services/Service.h"
class Scene;

class SceneManager : public Service
{
public:
    SceneManager();
    ~SceneManager();

    virtual void initialize() override;
    virtual void terminate() override;

    void To(Scene* nextScene);


private:
    Scene* _currentScene;
};

