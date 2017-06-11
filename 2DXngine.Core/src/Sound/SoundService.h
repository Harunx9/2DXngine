#pragma once
#include "..\Services\Service.h"
#include "../ContentManagement/DefaultAssets/Sound.h"
#include <map>

class SoundService :
    public Service
{
public:
    SoundService();
    ~SoundService();
    virtual void initialize() override;
    virtual void terminate() override;

    void play(Sound* sound, bool repeat = false);
    void stop(Sound* sound);
    void pause(Sound* sound);
};

