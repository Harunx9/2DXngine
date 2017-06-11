#pragma once
#include "..\Services\Service.h"
class SoundService :
    public Service
{
public:
    SoundService();
    ~SoundService();
    virtual void initialize() override;
    virtual void terminate() override;
private:
};

