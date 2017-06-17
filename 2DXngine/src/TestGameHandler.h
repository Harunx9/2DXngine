#pragma once
#include <Utils\GameHandler.h>
#include <Graphics\SpriteBatch.h>
#include <Graphics\Camera.h>

class TestGameHandler : public GameHandler
{
public:
    TestGameHandler();
    ~TestGameHandler();

    // Inherited via GameHandler
    virtual void initialize() override;
    virtual void update(float deltaTime) override;
    virtual void draw(float deltaTime) override;
    virtual void handleInput() override;

private:
    SpriteBatch* batch;
    Texture* texture;
    Camera* cam;
};

