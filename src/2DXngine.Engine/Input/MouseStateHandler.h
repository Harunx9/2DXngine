#pragma once
#include "../AppImplementations/SDLEvents/Mappers/MouseEventsMapper.h"
#include "../Utils/Events/EventHandler.h"
#include "../Utils/Macros/PropertyMacro.h"

class MouseStateHandler
{
public:
    MouseStateHandler(MouseEventsMapper * mapper);
    ~MouseStateHandler();

    void updateButtonsState(MouseButtonsState state);
    void updatePositionState(MousePositionState state);

    bool isButtonPressed(MouseButtons button);
    bool isButtonReleased(MouseButtons button);

    READONLY_PROPERTY(PointI, position)
private:
    MouseEventsMapper * _mapper;
    Binding<MouseButtonsState> _bindingButtons;
    Binding<MousePositionState> _bindingPosition;
    bool _mouseKeysStates[MAX_MOUSE_BUTTONS];
};

