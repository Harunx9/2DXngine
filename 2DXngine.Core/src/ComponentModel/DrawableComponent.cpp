#include "DrawableComponent.h"



DrawableComponent::DrawableComponent(const char* name) :
    Component(name),
    _isVisible(true)
{
}


DrawableComponent::~DrawableComponent()
{
    this->_owner = nullptr;
}

void DrawableComponent::hide()
{
    this->_isVisible = false;
}

void DrawableComponent::show()
{
    this->_isVisible = true;
}

bool DrawableComponent::get_isVisible()
{
    return this->_isVisible;
}
