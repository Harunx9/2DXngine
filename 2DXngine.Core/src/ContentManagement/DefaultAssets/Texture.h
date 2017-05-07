#pragma once
#include "../Asset.h"
#include <soil\src\SOIL.h>
#include <GL\glew.h>
#include "../AssetPath.h"
#include "Bitmap.h"
#include "../../Utils/Macros/PropertyMacro.h"

class Texture : public Asset
{
public:
    static Texture * load(AssetPath assetPath);

    Texture(AssetPath assetPath, Bitmap* bitmap);
    ~Texture();

    virtual void generate();
    void bind() const;

    READONLY_PROPERTY(GLuint, textureId)
    READONLY_PROPERTY(Bitmap*, bitmap)
};

