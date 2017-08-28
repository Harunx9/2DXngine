#include "FontComponent.h"
#include "../../Services/ServiceLocator.h"
#include "../../ContentManagement/ContentManagerService.h"
#include "../../ContentManagement/DefaultAssets/TTFont.h"

FontComponent::FontComponent(AssetPath path)
    : Component("FontComponent"),
    _path(path)
{
}

FontComponent::~FontComponent()
{
    this->_manager = nullptr;
    this->_font = nullptr;
}

void FontComponent::initialize(bool force)
{
    this->_manager = ServiceLocator::get<ContentManagerService>("ContentManagerService");
    this->_font = _manager->load<TTFont>(this->_path);
}

void FontComponent::terminate()
{
    this->_manager->unload(this->_path);
}
