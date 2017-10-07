#include "InputService.h"
#include "KeyboardStateHandler.h"
#include "MouseStateHandler.h"
#include "../Services/ServiceLocator.h"
#include "../AppImplementations/SDLEvents/SDLEventsMapperService.h"
#include "../AppImplementations/SDLEvents/Mappers/KeyboardEventMapper.h"
#include "../AppImplementations/SDLEvents/Mappers/MouseEventsMapper.h"

InputService::InputService(): Service("InputService")
{
}


InputService::~InputService()
{
}

void InputService::initialize()
{
    auto mappersService = ServiceLocator::get<SDLEventsMapperService>("SDLEventsMapperService");
    this->_keyboard = new KeyboardStateHandler(mappersService->getMapper<KeyboardEventMapper>(MapperType::KeyboardEvent));
    this->_mouse = new MouseStateHandler(mappersService->getMapper<MouseEventsMapper>(MapperType::MouseEvent));
}

void InputService::terminate()
{
    delete _keyboard;
    delete _mouse;
}
