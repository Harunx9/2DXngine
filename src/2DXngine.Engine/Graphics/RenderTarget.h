#pragma once
#include "../ContentManagement/DefaultAssets/Texture.h"

class RenderTarget : public Texture
{
public:
    RenderTarget(int width, int height);
    ~RenderTarget();
    virtual void generate() override;
    inline GLuint get_fbo() const
    {
        return this->_fbo;
    }
    void begin();
    void end();
private:
    GLuint _fbo;
};

