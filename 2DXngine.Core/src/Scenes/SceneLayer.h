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

struct DefaultScenes
{

};