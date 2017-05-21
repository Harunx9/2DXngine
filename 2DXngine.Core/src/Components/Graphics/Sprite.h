#pragma once
#include "../../ComponentModel/Component.h"
#include "../../ContentManagement/DefaultAssets/Texture.h"
#include "../../ContentManagement/ContentManagerService.h"
#include "../../Services/ServiceLocator.h"
#include <string>

class Sprite : public Component
{
public:
    ADD_TYPE_META_INFO()
        Sprite(std::string path);
    ~Sprite();

    // Inherited via Component
    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
private:
    Texture * _texture;
    ContentManagerService * _manager;
    std::string _path;
};

