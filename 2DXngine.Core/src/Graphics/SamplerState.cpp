#include "SamplerState.h"
#include "../ContentManagement/DefaultAssets/Texture.h"

SamplerState::SamplerState(TextureWrap wrap, TextureFilter filter)
{
    glGenSamplers(1, &this->_samplerId);
    this->changeWrap(wrap);
}

SamplerState::~SamplerState()
{
    glDeleteSamplers(1, &this->_samplerId);
}

void SamplerState::bind()
{
    glBindSampler(0, this->_samplerId);
}

void SamplerState::unbind()
{
    glBindSampler(0, 0);
}

void SamplerState::changeFilter(TextureFilter filter)
{
    glSamplerParameteri(this->_samplerId, GL_TEXTURE_MAG_FILTER, filter);
    glSamplerParameteri(this->_samplerId, GL_TEXTURE_MIN_FILTER, filter);
}

void SamplerState::changeWrap(TextureWrap wrap)
{
    glSamplerParameteri(this->_samplerId, GL_TEXTURE_WRAP_S, wrap);
    glSamplerParameteri(this->_samplerId, GL_TEXTURE_WRAP_T, wrap);
}
