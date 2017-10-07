#include "DrawableComponent.h"



DrawableComponent::DrawableComponent(SceneLayer layer, const char* name) :
    Component(name),
    _isVisible(true),
    _layer(layer)
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