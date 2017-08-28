#pragma once
#include "../../ComponentModel/Component.h"
#include "../../Utils/Macros/PropertyMacro.h"
#include "../../ContentManagement/AssetPath.h"
class TTFont;
class ContentManagerService;

class FontComponent : public Component
{
public:
    ADD_TYPE_META_INFO()
        FontComponent(AssetPath path);
    ~FontComponent();
    virtual void initialize(bool force = false) override;
    virtual void terminate() override;

    READONLY_PROPERTY(TTFont*, font)
private:
    AssetPath _path;
    ContentManagerService* _manager;
};

