#pragma once
#include "..\Services\Service.h"
#include "..\ContentManagement\DefaultAssets\Sound.h"
class MusicService :
    public Service
{
public:
    MusicService();
    ~MusicService();
    virtual void initialize() override;
    virtual void terminate() override;

    void play(Music* music, bool repeat = false);
    void pause();
    void stop();

private:
    Music * _currentMusic;
};

