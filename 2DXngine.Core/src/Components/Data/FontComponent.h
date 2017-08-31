#pragma once
#include "../../ComponentModel/Component.h"
#include "../../Utils/Macros/PropertyMacro.h"
#include "../../ContentManagement/AssetPath.h"
#include "../../Graphics/Color.h"

class TTFont;
class ContentManagerService;

class FontComponent : public Component
{
public:
    ADD_TYPE_META_INFO()
        FontComponent(AssetPath path, Color color);
    ~FontComponent();
    virtual void initialize(bool force = false) override;
    virtual void terminate() override;

    READONLY_PROPERTY(TTFont*, font)
    READONLY_PROPERTY(Color, color)
private:
    AssetPath _path;
    ContentManagerService* _manager;
};

