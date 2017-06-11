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

void WavSound::play(int channel, bool repeat)
{
    int loop = 1;
    if (repeat)
    {
        loop = -1;
    }
    Mix_PlayChannel(channel, this->_soundData, loop);
    this->_channel = channel;
    this->_curretnState = PLAYING;
}

void WavSound::pause()
{
    Mix_Pause(this->_channel);
    this->_curretnState = PAUSED;
}

void WavSound::stop()
{
    Mix_HaltChannel(this->_channel);
    this->_curretnState = STOPPED;
}

void WavSound::resume()
{
    if (this->get_soundState() == PAUSED)
        return;

    Mix_Resume(this->_channel);
    this->_curretnState = PLAYING;
}
