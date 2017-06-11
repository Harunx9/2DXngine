#include "SoundService.h"



SoundService::SoundService() : Service("SoundService")
{
}


SoundService::~SoundService()
{
}

void SoundService::initialize()
{
    //TODO move channels number to config file
    Mix_AllocateChannels(256);
    //TODO implement sound volume change in config file 
    Mix_Volume(-1, (int)(MIX_MAX_VOLUME * 0.5f));
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

void SoundService::terminate()
{
    Mix_AllocateChannels(0);
}


