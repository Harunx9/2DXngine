#include "BehaviorTreeEvaluator.h"

void BehaviorTreeEvaluator::evaluate(NodeInformation * info, AINode * tree)
{
    std::stack<AINode*> treeStack;
    treeStack.push(tree);

    while (treeStack.empty() == false)
    {
        AINode* node = treeStack.top();
        treeStack.pop();
        switch (node->get_type())
        {
        case AINodeType::NODE:
            this->evaluateNode(info, node, treeStack);
            break;
        case AINodeType::ROOT:
            this->evaluateRootNode(info, node, treeStack);
            break;
        case AINodeType::SELECTOR:
            this->evaluateSelector(info, node, treeStack);
            break;
        case AINodeType::SEQUENCE:
            this->evaluateSequencer(info, node, treeStack);
            break;
        }
    }
}

void BehaviorTreeEvaluator::evaluateRootNode(NodeInformation * info, AINode * root, std::stack<AINode*>& treeStack)
{
    if (root->evaluate(info))
    {
        for (auto & child : root->get_children())
            treeStack.push(child);
    }
}

void BehaviorTreeEvaluator::evaluateNode(NodeInformation * info, AINode * node, std::stack<AINode*>& treeStack)
{
    if (node->evaluate(info))
    {
        if (node->get_children().empty() == false)
        {
            for (auto & child : node->get_children())
                treeStack.push(child);
        }
        else
        {
            this->_currentNode = node;
        }
    }
}

void BehaviorTreeEvaluator::evaluateSelector(NodeInformation * info, AINode * selector, std::stack<AINode*>& treeStack)
{
    if (selector->evaluate(info))
    {
        for (auto & child : selector->get_children())
            treeStack.push(child);
    }
}

void BehaviorTreeEvaluator::evaluateSequencer(NodeInformation * info, AINode * sequencer, std::stack<AINode*>& treeStack)
{
    if (sequencer->evaluate(info))
    {
        auto seq = dynamic_cast<SequenceNode*>(sequencer);

        auto nextNode = seq->get_nextNode();

        if (nextNode->get_children().empty() == false)
        {
            for (auto & child : nextNode->get_children())
                treeStack.push(child);
        }
        else
        {
            this->_currentNode = nextNode;
        }
    }
}
