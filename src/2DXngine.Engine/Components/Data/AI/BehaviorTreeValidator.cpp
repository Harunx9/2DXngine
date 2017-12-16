#include "BehaviorTreeValidator.h"

bool BehaviorTreeValidator::validate(AINode * tree)
{
    if (tree->get_type() != AINodeType::ROOT)
        return false;

    if (tree->get_children().empty())
        return false;

    return true;
}