#pragma once
#include "GameObjectFactories.h"
#include "../../Scenes/SceneLoader.h"
#include "Parsers/TileMapParser.h"
class TiledMapLoader : public SceneLoader
{
public:
    TiledMapLoader(AssetPath path, GameObjectFactories* factories);
    ~TiledMapLoader();

    virtual std::vector<GameObject*> load() override;

private:
    TileMapParser* _parser;
    GameObjectFactories* _factories;
};

