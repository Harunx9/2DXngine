#pragma once
#include "../Asset.h"
#include "SDL.h"
#include "SDL_mixer.h"

class Sound : public Asset
{
public:
    static Sound* load(AssetPath path);
    ~Sound();
private:
    Sound(AssetPath path);

};

