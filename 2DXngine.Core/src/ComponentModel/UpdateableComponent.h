#pragma once
#include "Component.h"
#include "../TypeInformation/TypeMetaInfo.h"

class UpdateableComponent :
    public Component
{
public:
    ADD_TYPE_META_INFO()
    UpdateableComponent(const char* name = "Updateable");
    virtual ~UpdateableComponent();

    virtual void update(float deltaTime) = 0;

    void deactivate();
    void activate();
    bool get_isActive() const;

protected:
    bool _isActive;
};

