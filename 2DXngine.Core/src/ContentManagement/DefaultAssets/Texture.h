#pragma once
#include "../Asset.h"

class Texture : public Asset
{
public:
    static Texture * load(std::string path);
    ~Texture();

private:
    Texture(std::string path);
};

