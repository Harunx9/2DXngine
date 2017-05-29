#pragma once
#include "InputDefines.h"
#include "../AppImplementations/SDLEvents/Mappers/KeyboardEventMapper.h"
#include "../Utils/Events/EventHandler.h"

class KeyboardStateHandler
{
public:
    KeyboardStateHandler(KeyboardEventMapper* mapper);
    ~KeyboardStateHandler();

    inline bool isKeyPressed(KeyboardButtons key)
    {
        return this->_keyboardKeysStates[key] == true;
    }

    inline bool isKeyReleased(KeyboardButtons key)
    {
        return this->_keyboardKeysStates[key] == false;
    }

    void updateState(KeyState state);
private:
    KeyboardEventMapper* _mapper;
    Binding<KeyState> _binding;
    bool _keyboardKeysStates[KEYBOARD_SIZE];
};

