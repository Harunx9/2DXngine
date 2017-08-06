#pragma once
#include <limits>
#include <glm/glm.hpp>
#include "../Utils/Macros/PropertyMacro.h"
#define NOMINMAX

class Camera
{
public:
    Camera(int viewportWidth, int viewportHeight);
    ~Camera();

    inline float get_rotation() const
    {
        return this->_rotation;
    }

    inline void set_rotation(float rotation)
    {
        if (MIN_ROT < rotation && rotation < MAX_ROT)
            this->_rotation = rotation;
    }

    inline float get_zoom()const
    {
        return this->_zoom;
    }

    inline void set_zoom(float zoom)
    {
        if (MIN_ZOOM < zoom && zoom < MAX_ZOOM)
            this->_zoom = zoom;
    }

    glm::vec2 unproject(glm::vec2 screenPosition);
    glm::mat4 get_viewMatrix();

    PROPERTY(int ,viewportWidth)
    PROPERTY(int ,viewportHeight)
    PROPERTY(glm::vec2, position)
    PROPERTY(glm::vec2, origin)

private:
    float _zoom;
    float _rotation;

    const float MAX_ROT = std::numeric_limits<float>::max NOMINMAX ();
    const float MIN_ROT = std::numeric_limits<float>::lowest();

    const float MAX_ZOOM = std::numeric_limits<float>::max NOMINMAX ();
    const float MIN_ZOOM = std::numeric_limits<float>::lowest();
};

