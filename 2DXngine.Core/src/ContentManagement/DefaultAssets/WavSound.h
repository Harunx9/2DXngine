#pragma once
#include "Sound.h"
#include "../../Utils/Macros/PropertyMacro.h"

class WavSound : public Sound
{
public:
    static WavSound* load(AssetPath path);
    ~WavSound();
    virtual void play(int channel, bool repeat = false) override;
    virtual void pause() override;
    virtual void resume() override;
    virtual void stop() override;
    READONLY_PROPERTY(int, channel)
private:
    WavSound(AssetPath path);
    Mix_Chunk * _soundData;
};

