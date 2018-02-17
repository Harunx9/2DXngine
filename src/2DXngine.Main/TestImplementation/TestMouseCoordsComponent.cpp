#include "TestMouseCoordsComponent.h"
#include <Graphics/Camera.h>
#include <Input/InputService.h>
#include <Services/ServiceLocator.h>
#include <Input/MouseStateHandler.h>
#include <iostream>

TestMouseCoordsComponent::TestMouseCoordsComponent(Camera* camera) :
    UpdateableComponent("TestMouseCoordsComponent"),
    _camera(camera)
{
}


TestMouseCoordsComponent::~TestMouseCoordsComponent()
{
}

void TestMouseCoordsComponent::initialize(bool force)
{
    auto input = ServiceLocator::get<InputService>("InputService");
    this->_logger = ServiceLocator::get<LoggerService>("LoggerService");
    this->_mouse = input->get_mouse();
    this->activate();
}

void TestMouseCoordsComponent::terminate()
{
}

void TestMouseCoordsComponent::update(float deltaTime)
{
    auto mousePos = this->_mouse->get_position();
    auto worldPos = this->_camera->unproject(glm::vec2(mousePos.get_x(), mousePos.get_y()));

    //this->_logger->info("x: %f y: %f", worldPos.x, worldPos.y);
}
