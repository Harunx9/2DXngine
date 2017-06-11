#include "OggSound.h"

OggSound::OggSound(AssetPath path) : Music(path, DefaultAssetType::OGG_TYPE)
{
    const char* soundPath = path.get_fullPath().c_str();
    this->_musicData = Mix_LoadMUS(soundPath);
}

OggSound * OggSound::load(AssetPath path)
{
    return new OggSound(path);
}

OggSound::~OggSound()
{
    Mix_FreeMusic(this->_musicData);
}

void OggSound::play(bool repeat)
{
    int loop = 1;
    if (repeat)
    {
        loop = -1;
    }

    if (Mix_PlayMusic(this->_musicData, loop) != -1)
    {
        this->_currentState = SoundState::PLAYING;
    }
}

void OggSound::stop()
{
    Mix_HaltMusic();
    this->_currentState = SoundState::STOPPED;
}

void OggSound::pause()
{
    Mix_PauseMusic();
    this->_currentState = SoundState::PAUSED;
}

void OggSound::resume()
{
    if (this->_currentState == SoundState::PAUSED)
        return;

    Mix_ResumeMusic();
    this->_currentState = SoundState::PLAYING;
}
