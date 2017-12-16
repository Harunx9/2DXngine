#pragma once
#include <stack>
#include "../../../Utils/Macros/PropertyMacro.h"
#include "AINode.h"

class BehaviorTreeEvaluator
{
public:
    BehaviorTreeEvaluator() {};
    ~BehaviorTreeEvaluator() {};

    virtual void evaluate(NodeInformation* info, AINode* tree);
    READONLY_PROPERTY(AINode*, currentNode)

protected:
    virtual void evaluateRootNode(NodeInformation* info, AINode* root, std::stack<AINode*>& treeStack);
    virtual void evaluateNode(NodeInformation* info, AINode* node, std::stack<AINode*>& treeStack);
    virtual void evaluateSelector(NodeInformation* info, AINode* selector, std::stack<AINode*>& treeStack);
    virtual void evaluateSequencer(NodeInformation* info, AINode* sequencer, std::stack<AINode*>& treeStack);
};
