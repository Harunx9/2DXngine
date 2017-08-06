#include "ClickableComponent.h"
#include "../../Graphics/Camera.h"
#include "../../Input/InputService.h"
#include "../../Services/ServiceLocator.h"
#include "../Graphics/Transform.h"
#include "../../ComponentModel/GameObject.h"

ClickableComponent::ClickableComponent(Camera * camera)
    : UpdateableComponent("ClickableComponent"),
    _camera(camera)
{
}

ClickableComponent::~ClickableComponent()
{
}

void ClickableComponent::initialize(bool force)
{
    if (this->get_isInitialized() && !force) return;

    this->_mouse = ServiceLocator::get<InputService>("InputService")
        ->get_mouse();
}

void ClickableComponent::terminate()
{
    this->_mouse = nullptr;
}

void ClickableComponent::update(float deltaTime)
{

}

void ClickableComponent::resolveDependencies(bool force)
{
    this->_transform = this->_owner->findFirstComponentOfType<Transform>();
}
