#pragma once
#include "../../ComponentModel/UpdateableComponent.h"
class Camera;
class MouseStateHandler;
class Transform;

class ClickableComponent : public UpdateableComponent
{
public:
    ClickableComponent(Camera * camera);
    ~ClickableComponent();

    virtual void handle() = 0;
    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void update(float deltaTime) override;
    virtual void resolveDependencies(bool force = false) override;
private:
    Camera * _camera;
    MouseStateHandler* _mouse;
    Transform* _transform;
};

