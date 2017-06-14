#include "MusicService.h"



MusicService::MusicService() : Service("MusicService")
{
}


MusicService::~MusicService()
{
}

void MusicService::initialize()
{
	this->_currentMusic = nullptr;
}

void MusicService::terminate()
{
    this->_currentMusic = nullptr;
}

void MusicService::play(Music * music, bool repeat)
{
    if (this->_currentMusic != nullptr)
    {
        if (this->_currentMusic->get_musicState() == SoundState::PAUSED)
        {
            this->_currentMusic->resume();
            return;
        }
    }

    if (music != nullptr)
    {
        this->_currentMusic = music;
        this->_currentMusic->play(repeat);
    }
      
}

void MusicService::pause()
{
    if (this->_currentMusic != nullptr)
    {
        this->_currentMusic->pause();
    }
}

void MusicService::stop()
{
    if (this->_currentMusic != nullptr)
    {
        this->_currentMusic->stop();
        this->_currentMusic = nullptr;
    }
}
