#pragma once
#include "SDLEventMapper.h"
#include "../../Services/Service.h"
#include <vector>

class SDLEventsMapperService : public Service
{
public:
    SDLEventsMapperService();
    ~SDLEventsMapperService();

    void map(SDL_Event * sdlEvent);
    virtual void initialize() override;
    virtual void terminate() override;

private:
    void registerMapper(SDLEventMapper* mapper);
    std::vector<SDLEventMapper*> _mappers;
};

