#include "PostProcessTask.h"


PostProcessTask::PostProcessTask(std::string name) :
    PostProcessTask(name, true)
{
}

PostProcessTask::PostProcessTask(std::string name, bool isActive) :
    _name(name),
    _isActive(isActive)
{
}

PostProcessTask::~PostProcessTask()
{
}
