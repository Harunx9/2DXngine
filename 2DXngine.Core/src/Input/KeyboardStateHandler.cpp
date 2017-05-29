#include "KeyboardStateHandler.h"
#include <iostream>

KeyboardStateHandler::KeyboardStateHandler(KeyboardEventMapper * mapper)
{
    this->_mapper = mapper;
    this->_binding = CREATE_BINDING_WITH_PARAM(EventParameterHandler<KeyState>::get_nextID(), KeyboardStateHandler, updateState, KeyState);
    this->_mapper->keyStateIsChanged += _binding;
    for (size_t btn = 0; btn < KEYBOARD_SIZE; btn++)
    {
        this->_keyboardKeysStates[btn] = false;
    }
}

KeyboardStateHandler::~KeyboardStateHandler()
{
    this->_mapper->keyStateIsChanged -= _binding;
}

void KeyboardStateHandler::updateState(KeyState state)
{
    switch (state.state)
    {
    case ButtonState::PRESSED:
        this->_keyboardKeysStates[state.button] = true;
        std::cout << state.button << " is pressed" << std::endl;
        break;
    case ButtonState::RELEASED:
        this->_keyboardKeysStates[state.button] = false;
        std::cout << state.button << " is released" << std::endl;
        break;
    }

}
