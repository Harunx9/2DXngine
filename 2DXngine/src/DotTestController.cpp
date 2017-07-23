#include "DotTestController.h"
#include <Components\Graphics\Transform.h>

DotTestController::DotTestController()
{
}

DotTestController::~DotTestController()
{
}

void DotTestController::initialize(bool force)
{
    this->activate();
}

void DotTestController::terminate()
{
}

void DotTestController::update(float deltaTime)
{
    float newRot = this->_transform->get_rotation() + 0.1f;
    this->_transform->set_rotation(newRot);
}

void DotTestController::resolveDependencies(bool force)
{
    this->_transform = this->_owner->findFirstComponentOfType<Transform>();
}
