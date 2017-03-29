#include "SceneBehaviorManager.h"

SceneBehaviorManager::SceneBehaviorManager()
{
}


SceneBehaviorManager::~SceneBehaviorManager()
{
}

void SceneBehaviorManager::initialize()
{
    for (auto& behavior : this->_preUpdateBehaviors)
    {
        behavior->resolveDependencies();
    }

    for (auto& behavior : this->_postUpdateBehaviors)
    {
        behavior->resolveDependencies();
    }
}

void SceneBehaviorManager::terminate()
{
    for (auto& behavior : this->_preUpdateBehaviors)
    {
        delete behavior;
    }

    for (auto& behavior : this->_postUpdateBehaviors)
    {
        delete behavior;
    }
}

void SceneBehaviorManager::addBehavior(UpdateOrder order, SceneBehavior * behavior)
{
    switch (order)
    {
    case PRE_UPDTATE:
        this->_preUpdateBehaviors.push_back(behavior);
        break;
    case POST_UPDATE:
        this->_postUpdateBehaviors.push_back(behavior);
        break;
    }

}

void SceneBehaviorManager::preUpdate(float deltaTime)
{
    for (auto& behavior : this->_preUpdateBehaviors)
    {
        behavior->update(deltaTime);
    }
}

void SceneBehaviorManager::postUpdate(float deltaTime)
{
    for (auto& behavior : this->_postUpdateBehaviors)
    {
        behavior->update(deltaTime);
    }
}
