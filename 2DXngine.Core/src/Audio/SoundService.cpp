#include "SoundService.h"
#include "../Services/ServiceLocator.h"
#include "../Config/ConfigurationService.h"


SoundService::SoundService() : Service("SoundService")
{
}


SoundService::~SoundService()
{
}

void SoundService::initialize()
{
    this->_cfg = ServiceLocator::get<ConfigurationService>("ConfigurationService")->get_audio();
    //TODO move channels number to config file
    Mix_AllocateChannels(this->_cfg->get_channelsNumber());
    //TODO implement sound volume change in config file 
    this->changeVolume(this->_cfg->get_soundVolumeFactor() * this->_cfg->get_audioVolumeFactor());
}

void SoundService::play(Sound * sound, bool repeat)
{
    if (sound->get_soundState() == SoundState::PAUSED)
    {
        sound->resume();
    }
    sound->play(repeat);
}

void SoundService::stop(Sound * sound)
{
    sound->stop();
}

void SoundService::pause(Sound * sound)
{
    sound->pause();
}

void SoundService::changeVolume(float factor)
{
    Mix_Volume(-1, (int)(MIX_MAX_VOLUME * factor));
}

void SoundService::terminate()
{
    Mix_AllocateChannels(0);
}


