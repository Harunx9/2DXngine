#include "MouseEventsMapper.h"

MouseEventsMapper::MouseEventsMapper() : SDLEventMapper(MapperType::MouseEvent)
{
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
        MousePositionState positionState;
        positionState.position.set_x(sdlEvt->motion.x);
        positionState.position.set_y(sdlEvt->motion.y);
        auto handler = this->mousePositionStateChanged;
        if (handler.isUsed())
        {
            handler.invoke(positionState);
        }
    }
    break;
    case SDL_EventType::SDL_MOUSEBUTTONUP:
    {
        MouseButtonsState buttonSatate;
        buttonSatate.button = (MouseButtons)sdlEvt->button.button;
        buttonSatate.state = ButtonState::RELEASED;
        auto handler = this->mouseButtonsStateChanged;
        if (handler.isUsed())
        {
            handler.invoke(buttonSatate);
        }
    }
    break;
    case SDL_EventType::SDL_MOUSEBUTTONDOWN:
    {
        MouseButtonsState buttonSatate;
        buttonSatate.button = (MouseButtons)sdlEvt->button.button;
        buttonSatate.state = ButtonState::PRESSED;
        auto handler = this->mouseButtonsStateChanged;
        if (handler.isUsed())
        {
            handler.invoke(buttonSatate);
        }
    }
    break;
    }

}
