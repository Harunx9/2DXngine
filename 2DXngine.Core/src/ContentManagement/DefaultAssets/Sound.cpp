#include "Sound.h"



Sound::Sound(AssetPath path) : Asset(path, DefaultAssetType::WAV_TYPE)
{
}


Sound::~Sound()
{
}

Sound* Sound::load(AssetPath path)
{
    return nullptr;
}
