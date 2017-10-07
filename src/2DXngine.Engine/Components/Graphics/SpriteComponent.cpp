#include "SpriteComponent.h"
SpriteComponent::SpriteComponent(std::string path) :
    Component("SpriteComponent"),
    _path(path)
{
    this->_fileName = AssetPath::get_fileName(this->_path);
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::initialize(bool force)
{
    this->_manager = ServiceLocator::get<ContentManagerService>("ContentManagerService");
    if (this->_manager)
    {
        this->_texture = this->_manager->load<Texture>(AssetPath::create(this->_path));
    }
}

void SpriteComponent::terminate()
{
    auto path = this->_texture->get_path();
    this->_texture = nullptr;
    this->_manager->unload(path);
}
