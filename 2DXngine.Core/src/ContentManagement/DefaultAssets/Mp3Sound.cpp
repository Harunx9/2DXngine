#include "Mp3Sound.h"

Mp3Sound::Mp3Sound(AssetPath path) : Music(path, DefaultAssetType::MP3_TYPE)
{
    const char* soundPath = path.get_fullPath().c_str();
    this->_musicData = Mix_LoadMUS(soundPath);
}

Mp3Sound * Mp3Sound::load(AssetPath path)
{
    return new Mp3Sound(path);
}

Mp3Sound::~Mp3Sound()
{
    Mix_FreeMusic(this->_musicData);
}

void Mp3Sound::play(bool repeat)
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

void Mp3Sound::stop()
{
    Mix_HaltMusic();
    this->_currentState = SoundState::STOPPED;
}

void Mp3Sound::pause()
{
    Mix_PauseMusic();
    this->_currentState = SoundState::PAUSED;
}

void Mp3Sound::resume()
{
    if (this->_currentState == SoundState::PAUSED)
        return;

    Mix_ResumeMusic();
    this->_currentState = SoundState::PLAYING;
}