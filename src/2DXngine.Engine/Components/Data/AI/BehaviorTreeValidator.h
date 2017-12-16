#pragma once
#include "AINode.h"

class BehaviorTreeValidator
{
public:
    BehaviorTreeValidator() {}
    ~BehaviorTreeValidator() {}
    bool validate(AINode * tree);
};

