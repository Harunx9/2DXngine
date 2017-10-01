#include "PostProcessHandler.h"



PostProcessHandler::PostProcessHandler()
{
}


PostProcessHandler::~PostProcessHandler()
{
    for (auto& pair : this->_tasks)
        delete pair.second;

    this->_tasks.clear();
}

void PostProcessHandler::applyAllTasks(float deltaTime, Renderer * renderer, Camera * camera)
{
    for (auto& pair : this->_tasks)
        pair.second->apply(deltaTime, renderer, camera);
}

