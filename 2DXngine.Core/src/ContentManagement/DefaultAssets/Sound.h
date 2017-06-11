#pragma once
#include "../Asset.h"
#include "SDL_mixer.h"
#include "../../Utils/Macros/PropertyMacro.h"

enum SoundState {
    STOPPED,
    PLAYING,
    PAUSED
};

class Sound : public Asset
{
protected:
    SoundState _currentState;
    Sound(AssetPath path, const AssetType* type) : Asset(path, type) {}
public:
    virtual ~Sound() {}
    virtual void play(bool repeat = false) = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void stop() = 0;
    SoundState get_soundState()
    {
        return this->_currentState;
    }
};

class Music : public Asset
{
protected:
    SoundState _currentState;
    Music(AssetPath path, const AssetType* type) : Asset(path, type) {}
public:
    virtual ~Music() {}
    virtual void play(bool repeat = false) = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void stop() = 0;
    SoundState get_musicState()
    {
        return this->_currentState;
    }
};