#include "WavSound.h"

WavSound::WavSound(AssetPath path) : Sound(path, DefaultAssetType::WAV_TYPE)
{
    const char* soundPath = path.get_fullPath().c_str();
    this->_soundData = Mix_LoadWAV(soundPath);
}

WavSound::~WavSound()
{
    Mix_FreeChunk(this->_soundData);
}

WavSound* WavSound::load(AssetPath path)
{
    return new WavSound(path);
}

void WavSound::play(bool repeat)
{
    int loop = 1;
    if (repeat)
    {
        loop = -1;
    }

    this->_channel = Mix_PlayChannel(-1, this->_soundData, loop);
    
    if (this->_channel != -1)
    {
        this->_currentState = SoundState::PLAYING;
    }
}

void WavSound::pause()
{
    Mix_Pause(this->_channel);
    this->_currentState = SoundState::PAUSED;
}

void WavSound::stop()
{
    Mix_HaltChannel(this->_channel);
    this->_channel = -1;
    this->_currentState = SoundState::STOPPED;
}

void WavSound::resume()
{
    if (this->get_soundState() == SoundState::PAUSED)
        return;

    Mix_Resume(this->_channel);
    this->_currentState = SoundState::PLAYING;
}
