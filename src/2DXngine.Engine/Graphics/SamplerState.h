#pragma once
#include <GL/glew.h>
class Texture;

enum TextureWrap
{
    REPEAT = GL_REPEAT,
    MIRRORED_REPEAT = GL_MIRRORED_REPEAT,
    CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
    CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER
};

enum TextureFilter
{
    POINT_FILTER = GL_NEAREST,
    LINEAR_FILTER = GL_LINEAR
};

class SamplerState
{
public:
    SamplerState(TextureWrap wrap, TextureFilter filter);
    ~SamplerState();
    void bind();
    void unbind();

    void changeFilter(TextureFilter filter);
    void changeWrap(TextureWrap wrap);
public:
    GLuint _samplerId;
};

