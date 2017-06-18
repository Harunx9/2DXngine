#pragma once
#include <SDL.h>
#include "../Graphics/GraphicDevice.h"

class GameHandler
{
public:
    GameHandler();
    GameHandler(const GameHandler * other) = delete;
    ~GameHandler();
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