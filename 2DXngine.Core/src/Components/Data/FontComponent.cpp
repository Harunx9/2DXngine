#include "FontComponent.h"
#include "../../Services/ServiceLocator.h"
#include "../../ContentManagement/ContentManagerService.h"
#include "../../ContentManagement/DefaultAssets/TTFont.h"

FontComponent::FontComponent(AssetPath path, Color color)
    : Component("FontComponent"),
    _path(path),
    _color(color)
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
