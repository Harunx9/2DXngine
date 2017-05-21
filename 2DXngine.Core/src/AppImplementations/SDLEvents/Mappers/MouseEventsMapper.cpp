#include "MouseEventsMapper.h"



MouseEventsMapper::MouseEventsMapper() : SDLEventMapper(MapperType::MouseEvent)
{
    MouseState state = MouseState();

}


MouseEventsMapper::~MouseEventsMapper()
{
}

bool MouseEventsMapper::canMap(SDL_Event * sdlEvt)
{
    return sdlEvt->type == SDL_MOUSEMOTION ||
        sdlEvt->type == SDL_MOUSEWHEEL ||
        sdlEvt->type == SDL_MOUSEBUTTONUP ||
        sdlEvt->type == SDL_MOUSEBUTTONDOWN;
}

void MouseEventsMapper::mapAndNotify(SDL_Event * sdlEvt)
{
    switch (sdlEvt->type)
    {
    case SDL_EventType::SDL_MOUSEMOTION:
    {
        state.position.set_x(sdlEvt->motion.x);
        state.position.set_y(sdlEvt->motion.y);
    }
    break;
    case SDL_EventType::SDL_MOUSEBUTTONUP:
    {
        state.button = (MouseButtons)sdlEvt->button.button;
        state.state = ButtonState::RELEASED;
    }
    break;
    case SDL_EventType::SDL_MOUSEBUTTONDOWN:
    {
        state.button = (MouseButtons)sdlEvt->button.button;
        state.state = ButtonState::PRESSED;
    }
    break;
    }

    auto handler = this->mouseButtonsStateChanged;
    if (handler.isUsed())
    {
        handler.invoke(state);
    }
}
