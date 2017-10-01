#pragma once
#include <string>
#include "../../Utils/Macros/PropertyMacro.h"
class Renderer;
class Camera;
class PostProcessTask
{
public:
    PostProcessTask(std::string name);
    PostProcessTask(std::string name, bool isActive);
    ~PostProcessTask();

    void activate() { this->_isActive = true; }
    void deactivate() { this->_isActive = false; }
    virtual void initialize() = 0;
    virtual void apply(float deltaTime, Renderer* renderer, Camera* camera) = 0;

    READONLY_PROPERTY(std::string, name)
    READONLY_PROPERTY(bool, isActive)
};

