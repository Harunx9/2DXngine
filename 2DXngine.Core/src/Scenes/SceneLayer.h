#pragma once
#include <string>

class SceneLayer
{
public:
    SceneLayer(std::string name, int order);
    ~SceneLayer();

    bool eqals(SceneLayer sceneLayer);
    bool eqals(SceneLayer* sceneLayer);

private:
    int _order;
    std::string _name;
};

struct DefaultLayers
{
    const SceneLayer * const GUI_LAYER = new SceneLayer("GUI", 0);
    const SceneLayer * const GAMEPLAY_LAYER = new SceneLayer("GAMEPLAY", 0);
};
