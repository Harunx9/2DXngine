#pragma once
#include <ComponentModel/UpdateableComponent.h>
#include <Utils/Logger/LoggerService.h>
class Camera;
class MouseStateHandler;

class TestMouseCoordsComponent : public UpdateableComponent
{
public:
    ADD_TYPE_META_INFO()
    TestMouseCoordsComponent(Camera* camera);
    ~TestMouseCoordsComponent();

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void update(float deltaTime) override;
private:
    Camera* _camera;
    MouseStateHandler* _mouse;
    LoggerService* _logger;
};

