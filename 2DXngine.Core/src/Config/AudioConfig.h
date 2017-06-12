#pragma once
#include "ConfigSection.h"
#include "../Utils/Macros/PropertyMacro.h"
class AudioConfig : public ConfigSection
{
public:
    AudioConfig(inifile * ini, float soundVolumeFactor, float musicVolumeFactor, float audioVolumeFactor, int channelsNumber);
    ~AudioConfig();

    static AudioConfig * loadInternal(inifile* ini);

    inline float get_soundVolumeFactor() const
    {
        return this->_soundVolumeFactor;
    }

    inline void set_soundVolumeFactor(float soundVolumeFactor)
    {
        if (this->_soundVolumeFactor != soundVolumeFactor)
        {
            this->_soundVolumeFactor = soundVolumeFactor;
            this->_ini->SetDoubleValue("Audio", "SoundVolume", (double)this->_soundVolumeFactor);
            this->sectionUpdatedHandler();
        }
    }

    inline float get_musicVolumeFactor() const
    {
        return this->_musicVolumeFactor;
    }

    inline void set_musicVolumeFactor(float musicVolumeFactor)
    {
        if (this->_musicVolumeFactor != musicVolumeFactor)
        {
            this->_musicVolumeFactor = musicVolumeFactor;
            this->_ini->SetDoubleValue("Audio", "MusicVolume", (double)this->_musicVolumeFactor);
            this->sectionUpdatedHandler();
        }
    }

    inline float get_audioVolumeFactor() const
    {
        return this->_audioVolumeFactor;
    }

    inline void set_audioVolumeFactor(float audioVolumeFactor)
    {
        if (this->_audioVolumeFactor != audioVolumeFactor)
        {
            this->_audioVolumeFactor = audioVolumeFactor;
            this->_ini->SetDoubleValue("Audio", "AudioVolume", (double)this->_audioVolumeFactor);
            this->sectionUpdatedHandler();
        }
    }

    inline int get_channelsNumber() const
    {
        return this->_channelsNumber;
    }

private:

    float _soundVolumeFactor;
    float _musicVolumeFactor;
    float _audioVolumeFactor;
    int _channelsNumber;
};

