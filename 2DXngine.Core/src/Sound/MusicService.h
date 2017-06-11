#pragma once
#include "..\Services\Service.h"
class MusicService :
    public Service
{
public:
    MusicService();
    ~MusicService();
    virtual void initialize() override;
    virtual void terminate() override;
private:

};

