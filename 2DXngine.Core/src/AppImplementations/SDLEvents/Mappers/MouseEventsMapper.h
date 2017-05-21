#pragma once
#include "../SDLEventMapper.h"
#include "../../../Input/InputDefines.h"
#include "../../../Utils/Events/EventArgs.h"
#include "../../../Utils/Events/EventHandler.h"
#include "../../../Utils/Math/Point.h"
struct MouseState
{
    Point position;
    MouseButtons button;
    ButtonState state;
};

class MouseEventsMapper: public SDLEventMapper
{
public:
    EventParameterHandler<MouseState> mouseButtonsStateChanged;

    MouseEventsMapper();
    ~MouseEventsMapper();

    virtual bool canMap(SDL_Event * sdlEvt) override;
    virtual void mapAndNotify(SDL_Event * sdlEvt) override;

private:
    MouseState state;
};

