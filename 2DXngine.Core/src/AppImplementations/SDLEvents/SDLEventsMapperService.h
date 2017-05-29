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

    template<class TMapper>
    TMapper * getMapper(MapperType type);

private:
    void registerMapper(SDLEventMapper* mapper);
    std::vector<SDLEventMapper*> _mappers;
};

template<class TMapper>
inline TMapper * SDLEventsMapperService::getMapper(MapperType type)
{
    for (auto& mapper : this->_mappers)
    {
        if (mapper->get_type() == type)
            return (TMapper *)mapper;
    }

    return nullptr;
}
