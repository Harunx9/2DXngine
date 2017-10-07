#pragma once
#include <SDL.h>

#include "../../Utils/Macros/PropertyMacro.h"

enum class MapperType
{
    KeyboardEvent,
    MouseEvent,
    WindowEvent,
};


class SDLEventMapper
{
public:
    SDLEventMapper(MapperType type);
    virtual ~SDLEventMapper();
    
    virtual bool canMap(SDL_Event * sdlEvt) = 0;
    virtual void mapAndNotify(SDL_Event * sdlEvt) = 0;

    READONLY_PROPERTY(MapperType, type)
};

