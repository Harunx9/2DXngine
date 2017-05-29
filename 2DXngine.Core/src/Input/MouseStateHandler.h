#pragma once
#include "../AppImplementations/SDLEvents/Mappers/MouseEventsMapper.h"
#include "../Utils/Events/EventHandler.h"
#include "../Utils/Macros/PropertyMacro.h"

class MouseStateHandler
{
public:
    MouseStateHandler(MouseEventsMapper * mapper);
    ~MouseStateHandler();

    void updateState(MouseState state);

    bool isButtonPressed(MouseButtons button);
    bool isButtonReleased(MouseButtons button);

    READONLY_PROPERTY(Point, position)
private:
    MouseEventsMapper * _mapper;
    Binding<MouseState> _binding;
    bool _mouseKeysStates[MAX_MOUSE_BUTTONS];
};

