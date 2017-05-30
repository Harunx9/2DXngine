#pragma once
#include "../SDLEventMapper.h"
#include "../../../Input/InputDefines.h"
#include "../../../Utils/Events/EventArgs.h"
#include "../../../Utils/Events/EventHandler.h"
#include "../../../Utils/Math/Point.h"
struct MouseButtonsState
{
    MouseButtons button;
    ButtonState state;
};

struct MousePositionState
{
    Point position;
};

class MouseEventsMapper: public SDLEventMapper
{
public:
    EventParameterHandler<MouseButtonsState> mouseButtonsStateChanged;
    EventParameterHandler<MousePositionState> mousePositionStateChanged;

    MouseEventsMapper();
    ~MouseEventsMapper();

    virtual bool canMap(SDL_Event * sdlEvt) override;
    virtual void mapAndNotify(SDL_Event * sdlEvt) override;
};

