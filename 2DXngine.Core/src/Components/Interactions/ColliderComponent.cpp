#include "ColliderComponent.h"

ColliderComponent::ColliderComponent() : Component("ColliderComponent")
{
}

ColliderComponent::~ColliderComponent()
{
}

void ColliderComponent::initialize(bool force)
{

}

void ColliderComponent::terminate()
{
    this->_transform = nullptr;
}

void ColliderComponent::resolveDependencies(bool force)
{
    this->_transform = this->_owner->findFirstComponentOfType<Transform>();
}

bool ColliderComponent::is_collide(ColliderComponent* other)
{
    RectangleF _this = this->get_rectangle();
    RectangleF _other = other->get_rectangle();
    bool result = _this.insersect(&_other);

    if (result && onCollisionDetected.isUsed())
    {
        onCollisionDetected.invoke(other);
    }

    return result;
}
