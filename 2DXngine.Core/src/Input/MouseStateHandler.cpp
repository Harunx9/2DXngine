#include "MouseStateHandler.h"
#include <iostream>

MouseStateHandler::MouseStateHandler(MouseEventsMapper * mapper)
{
    this->_mapper = mapper;
    this->_binding = CREATE_BINDING_WITH_PARAM(EventParameterHandler<MouseState>::get_nextID(), MouseStateHandler, updateState, MouseState);
    this->_mapper->mouseButtonsStateChanged += _binding;
    for (size_t btn = 0; btn < KEYBOARD_SIZE; btn++)
    {
        this->_mouseKeysStates[btn] = false;
    }
}

MouseStateHandler::~MouseStateHandler()
{
}

void MouseStateHandler::updateState(MouseState state)
{
    if (this->_position.get_x() != state.position.get_x() &&
        this->_position.get_y() != state.position.get_y())
    {
        this->_position = state.position;
        std::cout << "mouse x: " << this->_position.get_x() << " mouse y: " << this->_position.get_y() << std::endl;
    }
    switch (state.state)
    {
    case ButtonState::PRESSED:
        this->_mouseKeysStates[state.button] = true;
        std::cout << state.button << " is pressed" << std::endl;
        break;
    case ButtonState::RELEASED:
        this->_mouseKeysStates[state.button] = false;
        std::cout << state.button << " is released" << std::endl;
        break;
    }
}

bool MouseStateHandler::isButtonPressed(MouseButtons button)
{
    return this->_mouseKeysStates[button];
}

bool MouseStateHandler::isButtonReleased(MouseButtons button)
{
    return this->_mouseKeysStates[button] == false;
}
