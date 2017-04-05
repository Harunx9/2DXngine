#pragma once
#include "../Services/Service.h"
class SceneManager : public Service
{
public:
    SceneManager();
    ~SceneManager();

    // Inherited via Service
    virtual void initialize() override;
    virtual void terminate() override;
};

