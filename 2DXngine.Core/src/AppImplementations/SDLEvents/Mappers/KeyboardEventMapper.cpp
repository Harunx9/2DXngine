#include "KeyboardEventMapper.h"



KeyboardEventMapper::KeyboardEventMapper() : SDLEventMapper(MapperType::KeyboardEvent)
{
}


KeyboardEventMapper::~KeyboardEventMapper()
{
}

bool KeyboardEventMapper::canMap(SDL_Event * sdlEvt)
{
    return sdlEvt->type == SDL_KEYUP ||
        sdlEvt->type == SDL_KEYDOWN;
}

void KeyboardEventMapper::mapAndNotify(SDL_Event * sdlEvt)
{
    KeyState state;
    state.button = (KeyboardButtons)sdlEvt->key.keysym.scancode;
    state.state = (ButtonState)sdlEvt->type;

    auto handler = this->keyStateIsChanged;
    if (handler.isUsed())
    {
        handler.invoke(state);
    }
}
