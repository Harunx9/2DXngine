#pragma once
#include "../../../ComponentModel/UpdateableComponent.h"
#include "../../Data/AI/AINode.h"
#include "../../Data/AI/BehaviorTreeEvaluator.h"
#include "../../Data/AI/BehaviorTreeValidator.h"

class AITreeExecutorBehavior : public UpdateableComponent
{
public:
    AITreeExecutorBehavior(
        AINode * tree,
        BehaviorTreeEvaluator * evaluator,
        BehaviorTreeValidator * validator);
    ~AITreeExecutorBehavior();

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void update(float deltaTime) override;

    virtual NodeInformation* CreateInfo() = 0;
private:
    BehaviorTreeEvaluator * _evaluator;
    BehaviorTreeValidator * _validator;
    AINode * _tree;
    bool _treeIsValid;
    NodeInformation* _info;
};

