#pragma once

#include "GameObject.h"
#include <vector>

template<typename TComponent>
std::vector<TComponent*> getAllComponentFromGameObjectAndChildren(GameObject * gameObject, bool exactType = true)
{
    std::vector<TComponent*> foundComponents;

    if (gameObject->haveChildern())
    {
        for (auto& child : gameObject->get_childern())
        {
            auto childComponents = getAllComponentFromGameObjectAndChildren<TComponent>(child, exactType);
            foundComponents.insert(foundComponents.end(), childComponents.begin(), childComponents.end());
        }
    }

    auto gameObjectComponents = gameObject->findAllComponentsOfType<TComponent>(exactType);
    foundComponents.insert(foundComponents.end(), gameObjectComponents.begin(), gameObjectComponents.end());

    return foundComponents;
}
