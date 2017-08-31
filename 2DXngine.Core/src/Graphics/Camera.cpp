#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <gl/glew.h>
#include <glm/glm.hpp>


Camera::Camera(int viewportWidth, int viewportHeight) :
    Camera(viewportWidth, viewportHeight, Colors::black){}

Camera::Camera(int viewportWidth, int viewportHeight, Color clearColor) :
    Camera(viewportWidth, viewportHeight, clearColor, TextureWrap::CLAMP_TO_EDGE, TextureFilter::LINEAR_FILTER) {}

Camera::Camera(int viewportWidth, int viewportHeight, Color clearColor, TextureWrap wrap, TextureFilter filter):
    _viewportWidth(viewportWidth),
    _viewportHeight(viewportHeight),
    _rotation(0.f),
    _zoom(1.0f),
    _clearColor(clearColor),
    _filter(filter),
    _wrap(wrap)
{
    this->_origin = glm::vec2(_viewportWidth * 0.5f, _viewportHeight * 0.5f);
}

Camera::~Camera()
{
}

glm::vec2 Camera::unproject(glm::vec2 screenPosition)
{
    auto projection = glm::ortho(0.f,
        static_cast<GLfloat>(this->_viewportWidth),
        static_cast<GLfloat>(this->_viewportHeight),
        0.f, -1.f, 1.f);
    auto view = this->get_viewMatrix();
    auto posvec3 = glm::vec3(screenPosition.x, this->_viewportHeight - screenPosition.y, 0.f);

    auto wordCoords = glm::unProject(posvec3, view, projection,
        glm::vec4(0.f, 0.f, this->_viewportWidth, this->_viewportHeight));

    return glm::vec2(wordCoords);
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
