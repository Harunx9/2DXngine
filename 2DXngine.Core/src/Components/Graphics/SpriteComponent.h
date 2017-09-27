#pragma once
#include "../../ComponentModel/Component.h"
#include "../../ContentManagement/DefaultAssets/Texture.h"
#include "../../ContentManagement/ContentManagerService.h"
#include "../../Services/ServiceLocator.h"
#include <string>
#include "../../Utils/Macros/PropertyMacro.h"

class SpriteComponent : public Component
{
public:
    ADD_TYPE_META_INFO()
        SpriteComponent(std::string path);
    ~SpriteComponent();

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;

    READONLY_PROPERTY(Texture*, texture)
    READONLY_PROPERTY(std::string, path)
    READONLY_PROPERTY(std::string, fileName)
private:
    ContentManagerService * _manager;
};