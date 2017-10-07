#include "TilesetsFactory.h"
#include "../Components/TileSetComponent.h"

TilesetsFactory::TilesetsFactory() : GameObjectFactory("TilesetsFactory")
{
}


TilesetsFactory::~TilesetsFactory()
{
}

std::vector<GameObject*> TilesetsFactory::map(TiledMap * map)
{
    auto tilesets = map->get_AllTileSets();

    auto go = new GameObject("tilesets");
    for (auto& tileset : tilesets)
    {
        go->addComponent(new TileSetComponent(
            tileset.get_firstGid(),
            tileset.get_tileWidth(),
            tileset.get_tileHeight(),
            tileset.get_spacing(),
            tileset.get_margin(),
            tileset.get_tileCount(),
            tileset.get_columns(),
            tileset.get_image().width,
            tileset.get_image().height,
            tileset.get_image().source
        ));

        go->addComponent(new SpriteComponent(tileset.get_image().source));
    }

    return std::vector<GameObject*>(1, go);
}
