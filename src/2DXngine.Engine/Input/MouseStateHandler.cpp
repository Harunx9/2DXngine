#include "MouseStateHandler.h"
#include <iostream>

MouseStateHandler::MouseStateHandler(MouseEventsMapper * mapper):
    _position(PointI(0,0))
{
    this->_mapper = mapper;

    this->_bindingButtons = CREATE_BINDING_WITH_PARAM(EventParameterHandler<MouseButtonsState>::get_nextID(), MouseStateHandler, updateButtonsState, MouseButtonsState);
    this->_mapper->mouseButtonsStateChanged += _bindingButtons;

    this->_bindingPosition = CREATE_BINDING_WITH_PARAM(EventParameterHandler<MousePositionState>::get_nextID(), MouseStateHandler, updatePositionState, MousePositionState);
    this->_mapper->mousePositionStateChanged += _bindingPosition;

    for (size_t btn = 0; btn < MAX_MOUSE_BUTTONS; btn++)
    {
        this->_mouseKeysStates[btn] = false;
    }
}

MouseStateHandler::~MouseStateHandler()
{
}

void MouseStateHandler::updateButtonsState(MouseButtonsState state)
{
    switch (state.state)
    {
    case ButtonState::PRESSED:
        this->_mouseKeysStates[state.button] = true;
        break;
    case ButtonState::RELEASED:
        this->_mouseKeysStates[state.button] = false;
        break;
    }
}

void MouseStateHandler::updatePositionState(MousePositionState state)
{
    if (this->_position.get_x() != state.position.get_x() &&
        this->_position.get_y() != state.position.get_y())
    {
        this->_position = state.position;
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
