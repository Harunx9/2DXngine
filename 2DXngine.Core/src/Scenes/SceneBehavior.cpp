#include "SceneBehavior.h"

SceneBehavior::SceneBehavior(Scene *const scene) :
    _scene(scene),
    _isActive(false)
{
    
}

SceneBehavior::~SceneBehavior()
{
    
}

void SceneBehavior::activate()
{
    this->_isActive = true;
}

void SceneBehavior::deactivate()
{
    this->_isActive = false;
}

bool SceneBehavior::get_isActive() const
{
    return this->_isActive;
}
