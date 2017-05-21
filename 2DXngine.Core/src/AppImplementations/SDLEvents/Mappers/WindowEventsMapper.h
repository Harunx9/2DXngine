#pragma once
#include "../SDLEventMapper.h"
#include "../../../Utils/Events/EventArgs.h"
#include "../../../Utils/Events/EventHandler.h"
#include "../../../Utils/Math/Rectangle.h"
#include "../../../Utils/Math/Point.h"

struct WindowState
{
    Point position;
    Point dimentsion;
    Rectangle rectangle;
};


class WindowEventsMapper : public SDLEventMapper
{
public:
    EventParameterHandler<WindowState> windowStateChanged;

    WindowEventsMapper();
    ~WindowEventsMapper();

    virtual bool canMap(SDL_Event * sdlEvt) override;
    virtual void mapAndNotify(SDL_Event * sdlEvt) override;

public:
    WindowState state;
};

