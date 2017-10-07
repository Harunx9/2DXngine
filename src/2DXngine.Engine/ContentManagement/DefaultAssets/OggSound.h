#pragma once
#include "Sound.h"

class OggSound : public Music
{
public:
    static OggSound* load(AssetPath path);
    ~OggSound();
    void play(bool repeat = false) override;
    virtual void pause() override;
    virtual void resume() override;
    void stop() override;
private:
    OggSound(AssetPath path);
    Mix_Music * _musicData;
};

