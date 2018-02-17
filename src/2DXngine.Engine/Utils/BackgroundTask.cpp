#include "BackgroundTask.h"
#include <chrono>

BackgroundTask::BackgroundTask(std::function<void()> executor) :
    _executor(executor),
    _state(TaskState::CREATED)
{
}

BackgroundTask::~BackgroundTask(){}

BackgroundTask * BackgroundTask::create(std::function<void()> executor)
{
    BackgroundTask * task = new BackgroundTask(executor);
    TaskPool::get().add(task);

    return task;
}

void BackgroundTask::waitForAll()
{
    bool wait = true;
    do
    {
        TaskPool::get().update();
        wait = TaskPool::get().anyTasksLeft();
    } while (wait);
}

BackgroundTask * BackgroundTask::then(std::function<void(BackgroundTask*)> continuator)
{
    this->_continuator = continuator;
    return this;
}

BackgroundTask * BackgroundTask::exec()
{
    this->_future = std::async(std::launch::async, this->_executor);
    this->_state = TaskState::STARTED;

    return this;
}

void BackgroundTask::update()
{
    auto result = this->_future.wait_for(std::chrono::seconds(0));
    if (result == std::future_status::ready)
    {
        this->_continuator(this);
        this->_state = TaskState::COMPLETED;
    }
}

void TaskPool::update()
{
    for (auto& task : this->_pool)
    {
        if (task->get_state() == TaskState::CREATED)
            task->exec();

        if (task->get_state() == TaskState::COMPLETED)
        {
            delete task;
            task = nullptr;
            continue;
        }

        task->update();
    }

    this->_pool.erase(
        std::remove_if(this->_pool.begin(), this->_pool.end(),
            [](BackgroundTask* task){return task == nullptr;}),
        this->_pool.end());
}
