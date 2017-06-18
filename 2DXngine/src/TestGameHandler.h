#pragma once
#include <Utils\GameHandler.h>
#include <Graphics\SpriteBatch.h>
#include <Graphics\Camera.h>
#include <ContentManagement\DefaultAssets\WavSound.h>
#include <ContentManagement\DefaultAssets\Mp3Sound.h>
#include <Audio\MusicService.h>
#include <Audio\SoundService.h>

class TestGameHandler : public GameHandler
{
public:
    TestGameHandler();
    ~TestGameHandler();

    // Inherited via GameHandler
    virtual void initialize() override;
    virtual void update(float deltaTime) override;
    virtual void draw(float deltaTime) override;
private:
    SpriteBatch* batch;
    Texture* texture;
    Camera* cam;
    float _camRot;
    Mp3Sound * _mp3;
    WavSound * _wav;
    MusicService * music;
    SoundService* sound;
};

