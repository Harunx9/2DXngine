#include "Sprite.h"

Sprite::Sprite(std::string path) :
    Component("SpriteComponent"),
    _path(path)
{
}

Sprite::~Sprite()
{
}

void Sprite::initialize(bool force)
{
    this->_manager = ServiceLocator::get<ContentManagerService>("ContentManager");
    if (this->_manager)
    {
        this->_texture = this->_manager->load<Texture>(AssetPath::create(this->_path));
    }
}

void Sprite::terminate()
{
    auto path = this->_texture->get_path();
    this->_texture = nullptr;
    this->_manager->unload(path);
}
