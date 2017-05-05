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
    this->_manager = ServiceLocator::get<ContentManager>("ContentManager");
    if (this->_manager)
    {
        this->_texture = this->_manager->load<Texture>(this->_path);
    }
}

void Sprite::terminate()
{
    this->_texture = nullptr;
    this->_manager->unload(this->_path);
}
