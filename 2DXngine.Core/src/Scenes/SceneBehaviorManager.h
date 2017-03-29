#pragma once
#include <vector>
#include "SceneBehavior.h"

enum UpdateOrder
{
    PRE_UPDTATE = 0,
    POST_UPDATE = 1
};

typedef std::vector<SceneBehavior*> scene_behavior_list;

class SceneBehaviorManager
{
public:
    SceneBehaviorManager();
    ~SceneBehaviorManager();

    void initialize();
    void terminate();

    void addBehavior(UpdateOrder order, SceneBehavior* behavior);

    void preUpdate(float deltaTime);
    void postUpdate(float deltaTime);

private:
    scene_behavior_list _preUpdateBehaviors;
    scene_behavior_list _postUpdateBehaviors;
};

