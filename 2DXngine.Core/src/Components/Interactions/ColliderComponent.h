#pragma once
#include "../../ComponentModel/Component.h"
#include "../../Utils/Math/RectangleF.h"
#include "../Graphics/Transform.h"
#include "../../Utils/Events/EventHandler.h"

class ColliderComponent : public Component
{
public:
    EventParameterHandler<ColliderComponent*> onCollisionDetected;

    ADD_TYPE_META_INFO()
    ColliderComponent();
    ~ColliderComponent();
    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void resolveDependencies(bool force = false) override;
    bool is_collide(ColliderComponent* other);
    
    RectangleF get_rectangle()
    {
        return RectangleF(this->_transform->get_x(),
            this->_transform->get_y(),
            this->_transform->get_width(),
            this->_transform->get_heihgt());
    }

private:
    Transform* _transform;
};

