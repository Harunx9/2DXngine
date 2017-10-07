#pragma once
#include <map>
#include "./PostProcessing/PostProcessTask.h"
class Renderer;
class Camera;

class PostProcessHandler
{
public:
    PostProcessHandler();
    ~PostProcessHandler();
    void addTask(PostProcessTask* task)
    {
        task->initialize();
        this->_tasks[task->get_name()] = task;
    }
    
    void switchOnTask(std::string name)
    {
        this->_tasks[name]->activate();
    }

    void switchOffTask(std::string name)
    {
        this->_tasks[name]->deactivate();
    }

    void removeTask(std::string name)
    {

        this->_tasks.erase("name");
    }

    void applyAllTasks(float deltaTime, Renderer* renderer, Camera* camera);
private:
    std::map<std::string, PostProcessTask*> _tasks;
};

