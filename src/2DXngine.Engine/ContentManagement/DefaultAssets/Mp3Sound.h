#pragma once
#include "Sound.h"

class Mp3Sound : public Music
{
public:
    static Mp3Sound* load(AssetPath path);
    ~Mp3Sound();
    virtual void play(bool repeat = false) override;
    virtual void pause() override;
    virtual void resume() override;
    virtual void stop() override;
private:
    Mp3Sound(AssetPath path);
    Mix_Music * _musicData;
};

