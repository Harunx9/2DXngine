#pragma once
#include "../SDLEventMapper.h"
#include "../../../Input/InputDefines.h"
#include "../../../Utils/Events/EventArgs.h"
#include "../../../Utils/Events/EventHandler.h"


struct KeyState
{
    KeyboardButtons button;
    ButtonState state;
};


class KeyboardEventMapper: public SDLEventMapper
{
public:
    EventParameterHandler<KeyState> keyStateIsChanged;

    KeyboardEventMapper();
    ~KeyboardEventMapper();

    virtual bool canMap(SDL_Event * sdlEvt) override;
    virtual void mapAndNotify(SDL_Event * sdlEvt) override;
};

