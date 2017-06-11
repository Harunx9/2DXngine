#pragma once
#include "../Asset.h"
#include "SDL_mixer.h"
#include "../../Utils/Macros/PropertyMacro.h"

class Sound : public Asset
{
protected:
    enum SoundState {
        STOPPED,
        PLAYING,
        PAUSED
    };
    SoundState _curretnState;
    Sound(AssetPath path, const AssetType* type) : Asset(path, type) {}
public:
    virtual ~Sound() {}
    virtual void play(int channel, bool repeat = false) = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void stop() = 0;
    SoundState get_soundState()
    {
        return this->_curretnState;
    }
};

class Music : public Asset
{
protected:
    enum MusicState {
        STOPPED,
        PLAYING,
        PAUSED
    };
    MusicState _curretnState;
    Music(AssetPath path, const AssetType* type) : Asset(path, type) {}
public:
    virtual ~Music() {}
    virtual void play(bool repeat = false) = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void stop() = 0;
    MusicState get_musicState()
    {
        return this->_curretnState;
    }
};