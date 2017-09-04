#include "../ContentManagement/AssetPath.h"
#include <vector>
#include "../ComponentModel/GameObject.h"
#pragma once

class SceneLoader
{
public:
    SceneLoader(AssetPath path) : _path(path){}
    ~SceneLoader() {}

    virtual std::vector<GameObject*> load() = 0;
protected:
    AssetPath _path;
};

