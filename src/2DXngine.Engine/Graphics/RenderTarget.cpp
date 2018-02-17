#include "RenderTarget.h"


RenderTarget::RenderTarget(int width, int height) :
    Texture(AssetPath::empty(), Bitmap::empty(width, height))
{
    this->generate();
}

RenderTarget::~RenderTarget()
{
    glDeleteBuffers(1, &this->_fbo);
}

void RenderTarget::generate()
{
    glBindFramebuffer(GL_FRAMEBUFFER, this->_fbo);
    this->bind();
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, this->get_textureId(), 0);
    GLenum drawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
    glDrawBuffers(1, drawBuffers);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::terminate();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void RenderTarget::begin()
{
    glBindFramebuffer(GL_FRAMEBUFFER, this->_fbo);
}

void RenderTarget::end()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
