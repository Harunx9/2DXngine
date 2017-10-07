#include "SceneLayer.h"

SceneLayer::SceneLayer(std::string name, int order):
    _name(name),
    _order(order)
{
}

SceneLayer::~SceneLayer()
{
}

bool SceneLayer::eqals(SceneLayer sceneLayer)
{
    return false;
}

bool SceneLayer::eqals(SceneLayer * sceneLayer)
{
    return false;
}

SceneLayer DefaultLayers::GUI_LAYER = SceneLayer("GUI", 0);
SceneLayer DefaultLayers::GAMEPLAY_LAYER = SceneLayer("GAMEPLAY", 1);