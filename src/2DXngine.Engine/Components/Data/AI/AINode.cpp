#include "AINode.h"

bool RootNode::evaluate(NodeInformation* information)
{
    return true;
}

void RootNode::execute(NodeInformation* information)
{
    return;
}

bool SelectorNode::evaluate(NodeInformation* information)
{
    return this->_evaluatorDelegate(information);
}

void SelectorNode::execute(NodeInformation* information)
{
    return;
}

bool SequenceNode::evaluate(NodeInformation* information)
{
    return this->_evaluatorDelegate(information);
}

void SequenceNode::execute(NodeInformation* information)
{
    return;
}

AINode* AINode::addChild(AINode * node)
{
    node->_parent = this;
    this->_children.push_back(node);
    return this;
}

bool LeafNode::evaluate(NodeInformation * information)
{
    return this->_evaluateDelegate(information);
}

void LeafNode::execute(NodeInformation * information)
{
    this->_executeDeleagate(information);
}
