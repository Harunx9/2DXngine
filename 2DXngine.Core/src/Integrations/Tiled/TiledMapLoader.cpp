#include "TiledMapLoader.h"

TiledMapLoader::TiledMapLoader(AssetPath path, GameObjectFactories* factories):
    SceneLoader(path),
    _factories(factories),
    _parser(new TileMapParser())
{
}

TiledMapLoader::~TiledMapLoader()
{
    delete _factories;
    delete _parser;
}

std::vector<GameObject*> TiledMapLoader::load()
{
    pugi::xml_document doc;
    auto result = doc.load_file(this->_path.get_fullPath().c_str());
    std::vector<GameObject*> objects;

    if (result.status == pugi::xml_parse_status::status_ok)
    {
        auto map = this->_parser->parse(doc.child("map"));
        objects = _factories->create(map);
    }

    return objects;
}
