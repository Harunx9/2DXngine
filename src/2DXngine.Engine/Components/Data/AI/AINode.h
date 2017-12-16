#pragma once
#include "../../../Utils/Macros/PropertyMacro.h"
#include <vector>
#include <functional>

enum class AINodeType
{
    NODE,
    ROOT,
    SELECTOR,
    SEQUENCE,
};

struct NodeInformation
{
    float deltaTime;
    bool isDirty;
};

class AINode
{
public:
    AINode() {}
    virtual ~AINode() 
    {
        this->_parent = nullptr;
        for (auto& child : this->_children)
        {
            delete child;
        }
        this->_children.clear();
    }

    virtual bool evaluate(NodeInformation* information) = 0;
    virtual void execute(NodeInformation* information) = 0;

    virtual AINodeType get_type() { return AINodeType::NODE; };

    std::vector<AINode*> get_children() { return this->_children; }
    AINode* get_parent() { return this->_parent; }

    AINode* addChild(AINode * node);
protected:
    std::vector<AINode*> _children;
    AINode* _parent;
};

class LeafNode : public AINode
{
public:
    LeafNode(std::function<bool(NodeInformation*)> evaluateDelegate, std::function<void(NodeInformation*)> executeDeleagate):
        _executeDeleagate(executeDeleagate), _evaluateDelegate(evaluateDelegate)
    {}
    virtual ~LeafNode() {}

    virtual bool evaluate(NodeInformation * information) override;
    virtual void execute(NodeInformation * information) override;
private:
    std::function<bool(NodeInformation*)> _evaluateDelegate;
    std::function<void(NodeInformation*)> _executeDeleagate;
};



class RootNode : public AINode
{
public:
    RootNode() {}
    virtual ~RootNode() {}

    virtual bool evaluate(NodeInformation* information) override;
    virtual void execute(NodeInformation* information) override;

    virtual AINodeType get_type() override { return AINodeType::ROOT; };
};

class SelectorNode : public AINode
{
public:
    SelectorNode(std::function<bool(NodeInformation*)> evaluatorDelegate) :
        _evaluatorDelegate(evaluatorDelegate) {}
    virtual ~SelectorNode() {}

    virtual bool evaluate(NodeInformation* information) override;
    virtual void execute(NodeInformation* information) override;

    virtual AINodeType get_type() override { return AINodeType::SELECTOR; };
private:
    std::function<bool(NodeInformation*)> _evaluatorDelegate;
};

class SequenceNode : public AINode
{
public:
    SequenceNode(std::function<bool(NodeInformation*)> evaluatorDelegate) :
        _evaluatorDelegate(evaluatorDelegate) {}
    virtual ~SequenceNode() {}

    virtual bool evaluate(NodeInformation* information) override;
    virtual void execute(NodeInformation* information) override;

    virtual AINodeType get_type() override { return AINodeType::SEQUENCE; };
    
    AINode* get_nextNode() 
    {
        this->_currentNode += 1;
        if (this->_currentNode >= this->get_maxNodes())
            this->_currentNode = 0;

        return this->_children[this->_currentNode];
    }

    int get_maxNodes() { return this->_children.size(); }
    READONLY_PROPERTY(int, currentNode)

private:
    std::function<bool(NodeInformation*)> _evaluatorDelegate;
};