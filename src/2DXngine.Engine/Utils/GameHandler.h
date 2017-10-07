#pragma once
#include <SDL.h>
#include "../Graphics/GraphicDevice.h"
class SceneManagerService;
class SpriteBatch;

class GameHandler
{
public:
    GameHandler();
    GameHandler(const GameHandler * other) = delete;
    virtual ~GameHandler();
    virtual void initialize() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void draw(float deltaTime) = 0;
    virtual void regiserUserServices() {}

    inline void set_device(GraphicDevice* device)
    {
        this->_device = device;
    }

protected:
    GraphicDevice* _device;
};

class GameHandlerWithScenes : public GameHandler
{
public:
    GameHandlerWithScenes() : GameHandler() {};
    virtual ~GameHandlerWithScenes();

    virtual void initialize() override;
    virtual void update(float deltaTime) override;
    virtual void draw(float deltaTime) override;

protected:
    SceneManagerService * _sceneManager;
};

class Game2DWithScenesHandler : public GameHandlerWithScenes
{
public:
    Game2DWithScenesHandler() : GameHandlerWithScenes() {};
    virtual ~Game2DWithScenesHandler();

    virtual void initialize() override;

protected:
    SpriteBatch * _batch;
};

class EmptyGameHandler : public GameHandler
{
public:
    EmptyGameHandler();
    EmptyGameHandler(const EmptyGameHandler * other) = delete;
    ~EmptyGameHandler();
    virtual void initialize() override;
    virtual void update(float deltaTime) override;
    virtual void draw(float deltaTime) override;
};