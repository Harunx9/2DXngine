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

    if (Mix_PlayMusic(this->_musicData, loop) == -1)
    {
        this->_curretnState = PLAYING;
    }
}

void OggSound::stop()
{
    Mix_HaltMusic();
    this->_curretnState = STOPPED;
}

void OggSound::pause()
{
    Mix_PauseMusic();
    this->_curretnState = PAUSED;
}

void OggSound::resume()
{
    if (this->_curretnState == PAUSED)
        return;

    Mix_ResumeMusic();
    this->_curretnState = PLAYING;
}
