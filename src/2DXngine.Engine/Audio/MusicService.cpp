#include "MusicService.h"
#include "../Services/ServiceLocator.h"
#include "../Config/ConfigurationService.h"
#include "SDL_mixer.h"

MusicService::MusicService() : Service("MusicService")
{
}


MusicService::~MusicService()
{
}

void MusicService::initialize()
{
    this->_currentMusic = nullptr;
    this->_cfg = ServiceLocator::get<ConfigurationService>("ConfigurationService")
        ->get_audio();

    this->changeVolume(this->_cfg->get_musicVolumeFactor() * this->_cfg->get_audioVolumeFactor());
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

void MusicService::changeVolume(float factor)
{
    Mix_VolumeMusic((int)(MIX_MAX_VOLUME * factor));
}
