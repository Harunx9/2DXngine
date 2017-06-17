#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>


Camera::Camera(int viewportWidth, int viewportHeight):
    _viewportWidth(viewportWidth),
    _viewportHeight(viewportHeight),
    _rotation(0.f),
    _zoom(1.0f)
{
    this->_origin = glm::vec2(_viewportWidth * 0.5f, _viewportHeight * 0.5f);
}

Camera::~Camera()
{
}

glm::mat4 Camera::get_viewMatrix()
{
    glm::mat4 vm = glm::mat4();
    vm = glm::translate(vm, glm::vec3(this->_origin, 0.f));
    vm = glm::rotate(vm, -this->_rotation, glm::vec3(0.f, 0.f, 1.f));
    vm = glm::scale(vm, glm::vec3(this->_zoom, this->_zoom, 1.f));
    vm = glm::translate(vm, glm::vec3(-this->_origin, 0.f));
    vm = glm::translate(vm, glm::vec3(-this->_position, 0.f));
    return vm;
}
