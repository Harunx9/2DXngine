#include "AudioConfig.h"



AudioConfig::AudioConfig(
    inifile * ini, float soundVolumeFactor, float musicVolumeFactor,
    float audioVolumeFactor, int channelsNumber) :
    ConfigSection(ini, ConfigurationSections::AUDIO),
    _soundVolumeFactor(soundVolumeFactor),
    _musicVolumeFactor(musicVolumeFactor),
    _audioVolumeFactor(audioVolumeFactor),
    _channelsNumber(channelsNumber)
{
}


AudioConfig::~AudioConfig()
{
}

AudioConfig * AudioConfig::loadInternal(inifile * ini)
{
    float soundVolumeFactor = (float)ini->GetDoubleValue("Audio", "SoundVolume", 1.0);
    float musicVolumeFactor = (float)ini->GetDoubleValue("Audio", "MusicVolume", 1.0);
    float audioVolumeFactor = (float)ini->GetDoubleValue("Audio", "AudioVolume", 1.0);
    int channelsNumber = (int)ini->GetLongValue("Audio", "Channels", 256);

    return new AudioConfig(ini, soundVolumeFactor, musicVolumeFactor, audioVolumeFactor, channelsNumber);
}
