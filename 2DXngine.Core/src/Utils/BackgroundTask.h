#pragma once
#include <vector>
#include <functional>
#include <future>
#include <algorithm>

class BackgroundTask;

enum TaskState
{
    CREATED,
    STARTED,
    COMPLETED
};

class TaskPool
{
public:
    TaskPool(TaskPool const&) = delete;
    TaskPool(TaskPool&&) = delete;
    TaskPool& operator=(TaskPool const&) = delete;
    TaskPool& operator=(TaskPool &&) = delete;

    static TaskPool& get() {
        static TaskPool instance;
        return instance;
    }

    void add(BackgroundTask * task)
    {
        this->_pool.push_back(task);
    }

    void update();

    bool anyTasksLeft()
    {
        return this->_pool.empty() == false;
    }

protected:
    TaskPool()
    {
        _pool = std::vector<BackgroundTask*>();
    }

    ~TaskPool()
    {
    }

private:
    std::vector<BackgroundTask*> _pool;
};

class BackgroundTask
{
public:
    ~BackgroundTask();

    static BackgroundTask* create(std::function<void()> executor);
    static void waitForAll();
    BackgroundTask* then(std::function<void(BackgroundTask*)> continuator);
    BackgroundTask* exec();
    

    inline TaskState get_state() const
    {
        return this->_state;
    }

    void update();

    BackgroundTask(BackgroundTask& other) = delete;
private:
    BackgroundTask(std::function<void()> executor);
    std::function<void()> _executor;
    std::function<void(BackgroundTask*)> _continuator;
    std::future<void> _future;
    TaskState _state;
};

