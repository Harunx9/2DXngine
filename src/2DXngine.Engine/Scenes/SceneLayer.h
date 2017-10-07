#pragma once
#include <string>
#include "../Utils/Macros/PropertyMacro.h"

class SceneLayer
{
public:
    SceneLayer(std::string name, int order);
    ~SceneLayer();

    bool eqals(SceneLayer sceneLayer);
    bool eqals(SceneLayer* sceneLayer);

    READONLY_PROPERTY(int, order)
    READONLY_PROPERTY(std::string, name)
};

struct DefaultLayers
{
    static SceneLayer GUI_LAYER;
    static SceneLayer GAMEPLAY_LAYER;
};
