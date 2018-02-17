#pragma once
#include <Utils/GameHandler.h>

class TestGameHandlerWithScenes : public Game2DWithScenesHandler
{
public:
    TestGameHandlerWithScenes();
    ~TestGameHandlerWithScenes();

    virtual void initialize() override;
};
