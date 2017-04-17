#pragma once
#include "../ContentManagement/DefaultAssets/Texture.h"

class RenderTarget : public Texture
{
public:
    RenderTarget(int width, int height, GLuint wrapS, GLuint wrapT, GLuint filterMin, GLuint filterMax);
    ~RenderTarget();
    
};

