#pragma once
#include "../Asset.h"
#if WIN32
    #include <soil/src/SOIL.h>
    #include <gl/glew.h>
#else
    #include <GL/glew.h>
    #include <SOIL.h>
#endif
#include "../AssetPath.h"
#include "Bitmap.h"
#include "../../Utils/Macros/PropertyMacro.h"

class Texture : public Asset
{
public:
    static Texture * load(AssetPath assetPath);

    Texture(AssetPath assetPath, Bitmap* bitmap);
    Texture(AssetPath assetPath, Bitmap* bitmap, GLint format);
    Texture(AssetPath assetPath, Bitmap* bitmap, GLint format, GLint internalFormat);
    ~Texture();

    void bind() const;

    READONLY_PROPERTY(GLuint, textureId)
    READONLY_PROPERTY(Bitmap*, bitmap)
protected:
    virtual void generate();
    GLint _format;
    GLint _internalFormat;
};

