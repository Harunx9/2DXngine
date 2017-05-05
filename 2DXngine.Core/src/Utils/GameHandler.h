#pragma once
#include <SDL.h>
class GameHandler
{
public:
    GameHandler();
    GameHandler(const GameHandler * other) = delete;
    ~GameHandler();
    virtual void initialize() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void draw(float deltaTime) = 0;
    virtual void handleInput() = 0;

    inline void set_window(SDL_Window* window)
    {
        this->_window = window;
    }

protected:
    SDL_Window* _window;
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
    virtual void handleInput() override;
};