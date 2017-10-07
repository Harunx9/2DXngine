#include <gtest\gtest.h>
#include <Utils\BackgroundTask.h>

TEST(BackgroundTaskTest, task_will_be_executed_correctly)
{
    int a = 0;

    auto task = BackgroundTask::create([&]() { a = 1; })
        ->then([&](BackgroundTask* task) { a = 3; });

    BackgroundTask::waitForAll();

    ASSERT_EQ(a, 3);
}