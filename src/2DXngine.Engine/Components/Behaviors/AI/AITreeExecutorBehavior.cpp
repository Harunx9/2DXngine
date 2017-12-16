#include "AITreeExecutorBehavior.h"

AITreeExecutorBehavior::AITreeExecutorBehavior(AINode * tree, BehaviorTreeEvaluator * evaluator, BehaviorTreeValidator * validator)
    :UpdateableComponent("AITreeExecutor"),
    _tree(tree),
    _evaluator(evaluator),
    _validator(validator)
{
}

AITreeExecutorBehavior::~AITreeExecutorBehavior()
{
    delete _evaluator;
    delete _validator;
    delete _tree;
}

void AITreeExecutorBehavior::initialize(bool force)
{
    this->_treeIsValid = this->_validator->validate(this->_tree);
    if (this->_treeIsValid == false)
        return;

    this->_info = CreateInfo();
}

void AITreeExecutorBehavior::terminate()
{
}

void AITreeExecutorBehavior::update(float deltaTime)
{
    if (this->_treeIsValid)
    {
        this->_info->deltaTime = deltaTime;
        if (this->_evaluator->get_currentNode() == nullptr)
        {
            this->_info->isDirty = true;
        }

        if (this->_info->isDirty)
        {
            this->_evaluator->evaluate(this->_info, this->_tree);
        }

        this->_evaluator->get_currentNode()->execute(this->_info);
    }
}
