#include "KeyboardStateHandler.h"
#include <iostream>
#include "../Services/ServiceLocator.h"
#include <string>

KeyboardStateHandler::KeyboardStateHandler(KeyboardEventMapper * mapper)
{
    this->_mapper = mapper;
    this->_binding = CREATE_BINDING_WITH_PARAM(EventParameterHandler<KeyState>::get_nextID(), KeyboardStateHandler, updateState, KeyState);
    this->_mapper->keyStateIsChanged += _binding;
    for (size_t btn = 0; btn < KEYBOARD_SIZE; btn++)
    {
        this->_keyboardKeysStates[btn] = false;
    }
    this->_logger = ServiceLocator::get<LoggerService>("LoggerService");
}

KeyboardStateHandler::~KeyboardStateHandler()
{
    this->_mapper->keyStateIsChanged -= _binding;
}

void KeyboardStateHandler::updateState(KeyState state)
{
    int keyNum = (int)state.button;
    switch (state.state)
    {
    case ButtonState::PRESSED:
        this->_keyboardKeysStates[keyNum] = true;
        this->_logger->debug("%d is pressed", keyNum);
        break;
    case ButtonState::RELEASED:
        this->_keyboardKeysStates[keyNum] = false;
        this->_logger->debug("%d is released", keyNum);
        break;
    }

}
