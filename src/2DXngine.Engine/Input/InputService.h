#pragma once
#include "../Services/Service.h"
#include "../Utils/Macros/PropertyMacro.h"
class KeyboardStateHandler;
class MouseStateHandler;

class InputService : public Service
{
public:
    InputService();
    ~InputService();

    virtual void initialize() override;
    virtual void terminate() override;
    
    READONLY_PROPERTY(KeyboardStateHandler*, keyboard)
    READONLY_PROPERTY(MouseStateHandler*, mouse)
};

