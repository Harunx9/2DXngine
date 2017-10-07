#include "WindowEventsMapper.h"



WindowEventsMapper::WindowEventsMapper() :
    SDLEventMapper(MapperType::WindowEvent)
{
}


WindowEventsMapper::~WindowEventsMapper()
{
}

bool WindowEventsMapper::canMap(SDL_Event * sdlEvt)
{
    return sdlEvt->type == SDL_WINDOWEVENT;
}

void WindowEventsMapper::mapAndNotify(SDL_Event * sdlEvt)
{
    switch (sdlEvt->window.event) {
    case SDL_WINDOWEVENT_MOVED:
    {
        state.position.set_x(sdlEvt->window.data1);
        state.position.set_y(sdlEvt->window.data2);
        state.rectangle.set_x(sdlEvt->window.data1);
        state.rectangle.set_y(sdlEvt->window.data2);
    }
    break;
    case SDL_WINDOWEVENT_RESIZED:
    {
        state.dimentsion.set_x(sdlEvt->window.data1);
        state.dimentsion.set_x(sdlEvt->window.data2);
        state.rectangle.set_width(sdlEvt->window.data1);
        state.rectangle.set_height(sdlEvt->window.data2);
    }
    break;
    case SDL_WINDOWEVENT_SIZE_CHANGED:
    {
        state.dimentsion.set_x(sdlEvt->window.data1);
        state.dimentsion.set_x(sdlEvt->window.data2);
        state.rectangle.set_width(sdlEvt->window.data1);
        state.rectangle.set_height(sdlEvt->window.data2);
    }
    break;
    }
}
