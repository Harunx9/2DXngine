#include "SDLEventsMapperService.h"
#include "Mappers\KeyboardEventMapper.h"
#include "Mappers\MouseEventsMapper.h"
#include "Mappers\WindowEventsMapper.h"


SDLEventsMapperService::SDLEventsMapperService() : Service("SDLEventsMapperService")
{
    this->_mappers = std::vector<SDLEventMapper*>();
}


SDLEventsMapperService::~SDLEventsMapperService()
{
    this->terminate();
}

void SDLEventsMapperService::registerMapper(SDLEventMapper* mapper)
{
    for (auto& registered_mapper: this->_mappers)
    {
        if (registered_mapper->get_type() == mapper->get_type())
            return;
    }

    this->_mappers.push_back(mapper);
}

void SDLEventsMapperService::map(SDL_Event * sdlEvent)
{
    for (auto& registered_mapper : this->_mappers)
    {
        if (registered_mapper->canMap(sdlEvent))
            registered_mapper->mapAndNotify(sdlEvent);
    }
}

void SDLEventsMapperService::initialize()
{
    //Todo register nessesry mappers
    this->registerMapper(new KeyboardEventMapper());
    this->registerMapper(new MouseEventsMapper());
    this->registerMapper(new WindowEventsMapper());
}

void SDLEventsMapperService::terminate()
{
    for (size_t mapper = 0; mapper <  this->_mappers.size(); ++mapper)
    {
        delete this->_mappers[mapper];
    }

    this->_mappers.clear();
}
