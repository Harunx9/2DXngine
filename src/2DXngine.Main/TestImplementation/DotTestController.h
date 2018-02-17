#pragma once
#include <ComponentModel/UpdateableComponent.h>
class Transform;

class DotTestController : public UpdateableComponent
{
public:
    ADD_TYPE_META_INFO()
        DotTestController();
    ~DotTestController();

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void update(float deltaTime) override;
    virtual void resolveDependencies(bool force = false) override;
private:
    Transform * _transform;
};
